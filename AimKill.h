//
// Created by sprin on 6/30/2023.
//

#ifndef INJECTORROOT_AIMKILL_H
#define INJECTORROOT_AIMKILL_H


#include <cstdint>
#include "Global.h"

class AimKill {
private:
    bool isDamage = false;
    float TimerTakeDamageinit = 0.0f;
    float TimerTakeDamageEnd = 0.0001f;
    void * WeaponOnHand = nullptr;
    uintptr_t  baseaddr;
public:
    void TakeDamage_Req(uintptr_t  Player, uintptr_t  LocalPlayer, void * WeaponOnHand, int Damage, int WeaponID, COW_GamePlay_IHAAMHPPLMG_o PlayerID, Vector3 localLocation, Vector3 enemyLocation, monoList<float *>CheckParams);
    void Start(Player, Player);
    void Stop();
};




#endif //INJECTORROOT_AIMKILL_H
