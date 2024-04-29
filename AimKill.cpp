//
// Created by sprin on 6/30/2023.
//

#include "AimKill.h"
#include "Il2Cpp.h"


void AimKill::TakeDamage_Req(uintptr_t  Player, uintptr_t  LocalPlayer, void * WeaponOnHan, int Damage, int WeaponID, COW_GamePlay_IHAAMHPPLMG_o PlayerID, Vector3 localLocation, Vector3 enemyLocation, monoList<float *>CheckParams)
{
    if(baseaddr){
        float Dist = Vector3::Distance(localLocation, enemyLocation);
        if(Dist > 1){
            auto ObjectPool = *(void **)((uintptr_t) LocalPlayer + offsets.weapon.GEGFCFDGGGP);
            if(ObjectPool)
            {
                if(!isDamage)
                {
                    Global::Weapon::SetStartDamage(WeaponOnHan, ObjectPool);
                    isDamage = true;
                }
                auto DamageInfo = Il2Cpp::NewClassObject(YK("Assembly-CSharp.dll"), YK("COW.GamePlay"), YK("ELMGJKHIIAA"));

                if (DamageInfo)
                {
                    *(COW_GamePlay_IHAAMHPPLMG_o *) ((uintptr_t) DamageInfo + offsets.weapon.DHGCIEKPBFA) = PlayerID;
                    *(int *) ((uintptr_t) DamageInfo + offsets.weapon.DBLBLKADCNP) = Damage;
                    *(int *) ((uintptr_t) DamageInfo + offsets.weapon.KENBMOOEHBG) = 1;
                    *(bool *) ((uintptr_t) DamageInfo + offsets.weapon.NNNADMOFPIE) = true;//unknown
                    *(bool *) ((uintptr_t) DamageInfo + offsets.weapon.MJIHLDJNHLF) = true;//unknown
                    *(void **) ((uintptr_t) DamageInfo + offsets.weapon.GPBDEDFKJNA) = WeaponOnHand; //Class Weapon
                    *(Vector3 *) ((uintptr_t) DamageInfo + offsets.weapon.CNEICNJFGLM) = localLocation;
                    *(Vector3 *) ((uintptr_t) DamageInfo + offsets.weapon.HECJHKEDFEB) = enemyLocation;//Hitpos

                    auto AceWall =  *(monoDictionary<uint8_t*, void **> **)((uintptr_t) ObjectPool + offsets.mADMMIICBNN.FHLFLAHCIBN);
                    if(AceWall)
                    {
                        *(monoDictionary<uint8_t *, void **> **) ((uintptr_t) DamageInfo + offsets.weapon.FHLFLAHCIBN) = AceWall;
                        *(byte *) ((uintptr_t) DamageInfo + offsets.weapon.ACAKHEABPEJ) =*(byte *) ((uintptr_t) ObjectPool + offsets.mADMMIICBNN.ACAKHEABPEJ) ;//unknown
                        *(Vector3 *) ((uintptr_t) DamageInfo +offsets.weapon.JNLGFLFLBHO) = *(Vector3 *) ((uintptr_t) ObjectPool + offsets.mADMMIICBNN.JNLGFLFLBHO);
                    }

                    auto WeaponData =  *(void **) ((uintptr_t) WeaponOnHand+ offsets.weapon.LAEMLAPIAFD);
                    if(WeaponData){
                        *(int *) ((uintptr_t) DamageInfo + offsets.weapon.PIAMIOFEBKF) = *(int *) ((uintptr_t) WeaponData +offsets.weapon.POBGKMDJMDC);
                    }

                    auto damagerWeaponDynamicInfo = Il2Cpp::NewClassObject(YK("Assembly-CSharp.dll"), YK("COW.GamePlay"), YK("MKFEKBKJCKE"));
                    if (damagerWeaponDynamicInfo)
                    {
                        int TypeWeapon = Global::Weapon::GetTypeWeapon(WeaponOnHand);
                        if(TypeWeapon !=3 && Dist > 1.0f) {
                            if (Global::Timer::get_time() >= TimerTakeDamageinit) {
                                TimerTakeDamageinit = Global::Timer::get_time() + TimerTakeDamageEnd;
                                Global::Weapon::TakeDamage(Player, Damage, PlayerID, DamageInfo, WeaponID, localLocation, enemyLocation, CheckParams, damagerWeaponDynamicInfo, 0);

                                Global::Weapon::StartWholeBodyFiring(LocalPlayer, WeaponOnHand);
                            }
                            Global::Weapon::StopFire(LocalPlayer, WeaponOnHand);

                        }else if (TypeWeapon == 3 ) {
                            if (Dist <= 1.0f) {
                                if (Global::Timer::get_time() >= TimerTakeDamageinit) {
                                    TimerTakeDamageinit = Global::Timer::get_time() + TimerTakeDamageEnd;

                                   Global::Weapon::TakeDamage(Player, Damage, PlayerID, DamageInfo, WeaponID, localLocation, enemyLocation, CheckParams, damagerWeaponDynamicInfo, 0);

                                    Global::Weapon::StartWholeBodyFiring(LocalPlayer, WeaponOnHand);
                                }
                                Global::Weapon::StopFire(LocalPlayer, WeaponOnHand);
                            }
                        }
                    }
                }
            }
        }
    }
}

void AimKill::Start(Player LocalPlayer, Player EnemyPlayer) {
    if(LocalPlayer.getObj() && EnemyPlayer.getObj()){
        baseaddr = Il2CppBase();

        WeaponOnHand = Global::Weapon::GetWeaponOnHand(LocalPlayer.getObj());
        if(WeaponOnHand)
        {
            auto WeaponID = Global::Weapon::GetWeaponID(WeaponOnHand);
            auto PlayerID = *(COW_GamePlay_IHAAMHPPLMG_o*)((uintptr_t) LocalPlayer.getObj() + offsets.weapon.KFMGKCJMCAM);
            auto Damage = Global::Weapon::GetDamage(WeaponOnHand);
            auto CheckParams = *(monoList<float *> *)((uintptr_t) WeaponOnHand + offsets.weapon.PIGOIHAOJGH);
            TakeDamage_Req(EnemyPlayer.getObj(),LocalPlayer.getObj(),WeaponOnHand,Damage,WeaponID,PlayerID,LocalPlayer.getHeadPosition(),EnemyPlayer.getHeadPosition(),CheckParams);
        }
    }
}

void AimKill::Stop() {
    WeaponOnHand = nullptr;
}
