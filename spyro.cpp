#include "spyro.hpp"


Spyro::Spyro(JsonEntityBuilder &builder, JsonItemBuilder & inventory, uint32_t uid) : 
    Entity(builder, inventory, uid)
{
    std::cout << Name() << " the spyro has entered the battle" << std::endl;
}



void Spyro::Flameshoot(Entity *target)
{
    Attack(target, 4.5, "Flameshoot");
}

void Spyro::Headbutt(Entity *target)
{
    Attack(target, GetStrength() * 1.5, "Headbutt");
}

void Spyro::OutputStatus() const
{
    std::cout << Class() << ": " << this->Name()
                << "\n\tCurrent HP: " << this->CurrentHP()
                << "\n\tIntelligence: " << this->GetIntelligence()
                << std::endl;

    PrintInventory();
}

void Spyro::WeaponAttack(Entity * target)
{
    Attack(target, GetStrength() * 0.5, "Scratch");
}

void Spyro::UseAction(Entity * target, const std::string& spellName, const std::string & args)
{
    if(spellName == "weapon_attack")
    {
        WeaponAttack(target);
        return;
    }
    if(spellName == "flameshoot")
    {
        Flameshoot(target);
        return;
    }
    if(spellName == "Headbutt")
    {
        Headbutt(target);
        return;
    }
    errorFindingAbility(spellName);
}