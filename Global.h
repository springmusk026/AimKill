
#ifndef MUSKCLIENT_GLOBAL_H
#define MUSKCLIENT_GLOBAL_H
#include <Logger.h>
#include <Unity/Unity.h>
#include "KittyMemory/KittyMemory.h"

#include "Offsets.h"

struct COW_GamePlay_IHAAMHPPLMG_o {
    uint32_t NBPDJAAAFBH;
    uint32_t JEDDPHIHGKL;
    uint8_t IOICFFEKAIL;
    uint8_t PHAFNFOFFDB;
    uint64_t BNFAIDHEHOM;
};

namespace Global {

    namespace Weapon
    {
        void SetStartDamage(void *,void*);
        void * GetWeaponOnHand(uintptr_t);
        int TakeDamage(uintptr_t _this, int baseDamage, COW_GamePlay_IHAAMHPPLMG_o playerId, void * DamageInfo, int weaponDataID, Vector3 firePos, Vector3 hitPos, monoList<float *> checkParams, void * damagerWeaponDynamicInfo, int damagerVehicleID);
        void StartWholeBodyFiring(uintptr_t ,void *);
        void StopFire(uintptr_t ,void *);
        int GetDamage(void *);
        int GetTypeWeapon(void *);
        int GetWeaponID(void *);
    }
    namespace Timer
    {
        float get_time();
    }

}



#endif //MUSKCLIENT_GLOBAL_H
