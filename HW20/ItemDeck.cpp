#include "ItemDeck.h"

#include "Item.h"

ItemDeck::ItemDeck()
{



    m_itemsDataBase =
            { new Weapon{"The Sword of DOOM", 5},
              new UndeadWeapon{"Stinky knife", 2},
              new UndeadWeapon{"Holy grenade", 4} };
}

ItemDeck::~ItemDeck()
{

}

std::vector<Item*> ItemDeck::generateItems() const
{

    return m_itemsDataBase;
}