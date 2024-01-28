#include "ModifierDeck.h"
#include "Modifier.h"
#include <algorithm>

ModifierDeck::ModifierDeck()
{
    m_modifiersDatabase =
            {
                    new SimpleModifier{3},
                    new SimpleModifier{3},
                    new SimpleModifier{2},
                    new SimpleModifier{2},
                    new SimpleModifier{2},
                    new SimpleModifier{4},
                    new SimpleModifier{1},
                    new SimpleModifier{1},
                    new SimpleModifier{1},
                    new DoubleMunchkinLevel{},
                    new DoubleMunchkinLevel{},
                    new HalvesMonsterLevel{Tribe::Undead},
                    new HalvesMonsterLevel{Tribe::God}
            };
}

ModifierDeck::~ModifierDeck()
{
    for (Modifier* modifier : m_modifiersDatabase)
    {
        delete modifier;
    }
    m_modifiersDatabase.clear();
}

Modifier* ModifierDeck::generateModifier() const
{
    if (m_modifiersDatabase.empty())
    {
        m_modifiersDatabase = {
                new SimpleModifier{3},
                new SimpleModifier{3},
                new SimpleModifier{2},
                new SimpleModifier{2},
                new SimpleModifier{2},
                new SimpleModifier{4},
                new SimpleModifier{1},
                new SimpleModifier{1},
                new SimpleModifier{1},
                new DoubleMunchkinLevel{},
                new DoubleMunchkinLevel{},
                new HalvesMonsterLevel{Tribe::Undead},
                new HalvesMonsterLevel{Tribe::God}
        };
    }

    unsigned int idx = std::rand() % m_modifiersDatabase.size();
    return m_modifiersDatabase[idx];
}
