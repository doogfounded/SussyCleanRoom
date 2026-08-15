# purge_crt_steps.py
import json
import re

PLAN_PATH = r"./specs_output/sorted_execution_plan.json"    

# Patterns matching MSVC, UCRT, and C Standard Library internals
CRT_PATTERNS = [
    r"^__?scrt",       # Startup CRT
    r"^___?[a-z]?crt",  # App CRT / dcrt / vcrt
    r"^__?security",   # Buffer security checks (__security_check_cookie)
    r"^__?guard",      # Control Flow Guard (__guard_check_icall)
    r"_nolock$",       # UCRT thread-unsafe internal functions
    r"construct_ptd",  # Per-thread data
    r"^_?alloca",      # Stack allocation
    r"^__calloc",      # Heap allocation
    r"^__fileno",      # File descriptors
    r"^DllMain$",      # DLL Entry point
    r"^_RTC_",         # Run-time checks
    r"^_tlg",         # Telemetry
    r"^_sdd",
    r"^_sd",
    r"^_s",
    r"^_sdh",
    r"^__s",
    r"^_d",
    r"^FID_",
    r"^__unlock",
    r"^__lock",
    r"^_C_specific_handler",
    r"^_EH_prolog",
    r"^_chkesp",
    r"^_adjust_flt_exc_handler_for_local",
    r"^__alloca",
    r"^_Mtxlock",
    r"^__lock_locales",
    r"^_Lockit",
    r"^replace_current_thread_locale_nolock",
    r"^__invoke_watson$",
    r"^_abort$"
]

# Combine into a single compiled Regex
CRT_REGEX = re.compile("|".join(CRT_PATTERNS), re.IGNORECASE)

with open(PLAN_PATH, "r") as f:
    plan = json.load(f)

original_steps = plan["execution_order"]
clean_steps = []
purged_names = []

for step in original_steps:
    name = step["name"]
    if CRT_REGEX.search(name):
        purged_names.append(name)
    else:
        clean_steps.append(step)

# Re-index remaining clean steps
for idx, step in enumerate(clean_steps, 1):
    step["step"] = idx

plan["execution_order"] = clean_steps
plan["total_functions"] = len(clean_steps)

with open(PLAN_PATH, "w") as f:
    json.dump(plan, f, indent=2)

print(f"[+] Purged {len(purged_names)} CRT/Internal functions:")
for name in purged_names[:10]:  # Print first 10
    print(f"    - Removed: {name}")
if len(purged_names) > 10:
    print(f"    ... and {len(purged_names) - 10} more.")

print(f"\n[+] Total Clean Execution Steps Remaining: {len(clean_steps)}")