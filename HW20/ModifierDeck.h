
#pragma once
#include <vector>

class Modifier;

class ModifierDeck
{
public:
    ModifierDeck();
    ~ModifierDeck();

    Modifier* generateModifier() const;

    std::vector<Modifier*> generateModifiers() const { return m_modifiersDatabase; }

private:
    mutable std::vector<Modifier*> m_modifiersDatabase;
};
