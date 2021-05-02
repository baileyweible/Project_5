#ifndef SPYRO_HPP
#define SPYRO_HPP


#include "JsonEntityBuilder.hpp"
#include "entity.hpp"

class Spyro : public Entity
{
private:
    void Flameshoot(Entity * target);
    void Headbutt(Entity * target);
    void Scratch(Entity * target);

public:

    Sypro(JsonEntityBuilder &builder, JsonItemBuilder & inventory, uint32_t uid);

    virtual void OutputStatus() const override;
    virtual void WeaponAttack(Entity * target) override;

    virtual void UseAction(Entity * target, const std::string& spellName, const std::string & args) override;
};


#endif
