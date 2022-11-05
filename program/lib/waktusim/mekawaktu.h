#include "../inventory/inventory.h"
#include "../deliverylist/deliverylist.h"
#include "../listmakanan/listmakanan.h"
#include "../olahmakanan/olahmakanan.h"
#include "../state/state.h"
#include "../boolean.h"

void StartTimeSimulator(TIME *t);
void UpdateActionTime(State *S);
void UpdateGlobalTime(TIME *t, TIME t2);
void UpdateWaitTime(State *S, TIME t);