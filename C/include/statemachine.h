#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#define TEMP_WARN_C        85.0
#define TEMP_CRIT_HIGH_C   105.0
#define TEMP_CRIT_LOW_C    5.0

#define STATE_INIT 0
#define STATE_OPERATION_LEVEL 1
#define STATE_WARNING_LEVEL 2
#define STATE_CRITICAL_LEVEL 3
#define STATE_RESET 4

void apply_state_machine(float temp);

#endif // STATEMACHINE_H