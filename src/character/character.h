#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
    public:
        Character();
        ~Character();

        //accessor methods
        float get_health();
        float get_baseAttack();
        float get_armourValue();
        float get_weaponValue();

        float get_strength();
        float get_dexterity();
        float get_intelligence();
        float get_constitution();
        float get_perception();
        float get_luck();

        bool get_hasWeapon();
        bool get_hasCritical();
        bool get_isDead();

        void set_health(float);
        void set_baseAttack(float);
        void set_armourValue(float);
        void set_weaponValue(float);

        void set_strength(float);
        void set_dexterity(float);
        void set_intelligence(float);
        void set_constitution(float);
        void set_perception(float);
        void set_luck(float);

        void set_hasWeapon(bool);
        void set_hasCritical(bool);
        void set_isDead(bool);

        //action methods
        float attack();
        void takeDamage(float);

        bool chanceCritical();
        void die();

    protected:
        float health;
        float baseAttack;

        float armourValue;
        float weaponValue;

        // 1 - 10
        float strength; // affects attack damage
        float dexterity; // lockpicking
        float intelligence; // hacking - doors, terminals, etc...
        float constitution; // determines health
        float perception; // stealth, detection
        float luck; // crits, loot

        bool hasWeapon;
        bool hasCritical;
        bool isDead;
};

#endif
