#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{
    // Étape 1 : Créer un objet Data
    Data* original = new Data(42, "Test Object", 3.14159);
    
    std::cout << "-------------- original" << std::endl;
    std::cout << "ptr : " << original << std::endl;
    std::cout << "id : " << original->id << std::endl;
    std::cout << "name : " << original->name << std::endl;
    std::cout << "value : " << original->value << std::endl;
    std::cout << std::endl;
    
    // Étape 2 : Sérialiser (pointeur → entier)
    uintptr_t serialized = Serializer::serialize(original);
    
    std::cout << "-------------- ptr > int" << std::endl;
    std::cout << "int : " << serialized << std::endl;
    std::cout << "hexa : 0x " << std::hex << serialized << std::dec << std::endl;
    std::cout << std::endl;
    
    // Étape 3 : Désérialiser (entier → pointeur)
    Data* deserialized = Serializer::deserialize(serialized);
    
    std::cout << "--------------  int > ptr" << std::endl;
    std::cout << "ptr : " << deserialized << std::endl;
    std::cout << "id : " << deserialized->id << std::endl;
    std::cout << "name : " << deserialized->name << std::endl;
    std::cout << "value : " << deserialized->value << std::endl;
    std::cout << std::endl;
    
    // Étape 4 : Vérification que ça fonctionne
    std::cout << "-------------- check" << std::endl;
    std::cout << "original == deserialized : " << (original == deserialized ? "OUI" : "NON") << std::endl;
    std::cout << "same id : " << (original->id == deserialized->id ? "OUI" : "NON") << std::endl;
    std::cout << "same name : " << (original->name == deserialized->name ? "OUI" : "NON") << std::endl;
    std::cout << "same value : " << (original->value == deserialized->value ? "OUI" : "NON") << std::endl;
    
    // Nettoyage
    delete original; // Attention : deserialized pointe vers la même adresse !
    
    return 0;
}