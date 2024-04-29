
void Global::Weapon::SetStartDamage(void * Player, void * ObjectPoolCallbackBase) {
    if (Player){
        uintptr_t (*func)(void *,void *);
        func =  (uintptr_t (*)(void *,void *))(offsets.weapon.SetStartDamage);
        func(Player,ObjectPoolCallbackBase);
    }
}

void * Global::Weapon::GetWeaponOnHand(uintptr_t Player) {
    if (Player){
        void * (*func)(uintptr_t );
        func =  (void * (*)(uintptr_t ))(offsets.weapon.GetWeaponOnHand);
        return func(Player);
    }
    return nullptr;
}
int Global::Weapon::TakeDamage(uintptr_t  _this, int baseDamage, COW_GamePlay_IHAAMHPPLMG_o Damage, void * DamageInfo, int weaponDataID, Vector3 firePos, Vector3 hitPos, monoList<float *> checkParams, void * damagerWeaponDynamicInfo, int damagerVehicleID) {
    if (_this){
        int (*func)(uintptr_t ,int,COW_GamePlay_IHAAMHPPLMG_o,void *,int,Vector3,Vector3,monoList<float *>,void *,uint);
        func =  (int (*)(uintptr_t ,int,COW_GamePlay_IHAAMHPPLMG_o,void *,int,Vector3,Vector3,monoList<float *>,void *,uint))(offsets.weapon.TakeDamage);
        return func(_this,baseDamage,Damage,DamageInfo,weaponDataID,firePos,hitPos,checkParams,damagerWeaponDynamicInfo,damagerVehicleID);
    }
    return 0;
}

void Global::Weapon::StartWholeBodyFiring(uintptr_t  Player, void * ObjectPoolCallbackBase) {
    if (Player){
        uintptr_t (*func)(uintptr_t ,void *);
        func =  (uintptr_t (*)(uintptr_t ,void *))(offsets.weapon.StartWholeBodyFiring);
        func(Player,ObjectPoolCallbackBase);
    }
}

void Global::Weapon::StopFire(uintptr_t  Player, void * ObjectPoolCallbackBase) {
    if (Player){
        uintptr_t (*func)(uintptr_t ,void *);
        func =  (uintptr_t (*)(uintptr_t ,void *))(offsets.weapon.StopFire);
        func(Player,ObjectPoolCallbackBase);
    }
}

int Global::Weapon::GetDamage(void * Player) {
    if (Player){
        int (*func)(void *);
        func =  (int (*)(void *))(offsets.weapon.GetDamage);
        return func(Player);
    }
    return 0;
}
int Global::Weapon::GetTypeWeapon(void * Player) {
    if (Player){
        int (*func)(void *);
        func =  (int (*)(void *))(offsets.weapon.GetTypeWeapon);
        return func(Player);
    }
    return 0;
}

int Global::Weapon::GetWeaponID(void * Player) {
    if (Player){
        int (*func)(void *);
        func =  (int (*)(void *))(offsets.weapon.GetWeaponID);
        return func(Player);
    }
    return 0;
}
float Global::Timer::get_time() {
    if (offsets.timer.get_time){
        float (*func)();
        func =  (float (*)())(offsets.timer.get_time);
        return func();
    }
    return 0;
}
