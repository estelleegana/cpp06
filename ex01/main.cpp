#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{
    // Étape 1 : Créer un objet Data
    Data* original = new Data(42, "Test Object", 3.14159);
    
    std::cout << "-------------- original" << std::endl;
    std::cout << "Adresse : " << original << std::endl;
    std::cout << "ID : " << original->id << std::endl;
    std::cout << "Name : " << original->name << std::endl;
    std::cout << "Value : " << original->value << std::endl;
    std::cout << std::endl;
    
    // // Étape 2 : Sérialiser (pointeur → entier)
    // uintptr_t serialized = Serializer::serialize(original);
    
    // std::cout << "Après sérialisation :" << std::endl;
    // std::cout << "Valeur entière : " << serialized << std::endl;
    // std::cout << "En hexadécimal : 0x" << std::hex << serialized << std::dec << std::endl;
    // std::cout << std::endl;
    
    // // Étape 3 : Désérialiser (entier → pointeur)
    // Data* deserialized = Serializer::deserialize(serialized);
    
    // std::cout << "Après désérialisation :" << std::endl;
    // std::cout << "Adresse : " << deserialized << std::endl;
    // std::cout << "ID : " << deserialized->id << std::endl;
    // std::cout << "Name : " << deserialized->name << std::endl;
    // std::cout << "Value : " << deserialized->value << std::endl;
    // std::cout << std::endl;
    
    // // Étape 4 : Vérification que ça fonctionne
    // std::cout << "=== Vérifications ===" << std::endl;
    // std::cout << "original == deserialized : " << (original == deserialized ? "OUI" : "NON") << std::endl;
    // std::cout << "Même contenu ID : " << (original->id == deserialized->id ? "OUI" : "NON") << std::endl;
    // std::cout << "Même contenu Name : " << (original->name == deserialized->name ? "OUI" : "NON") << std::endl;
    // std::cout << "Même contenu Value : " << (original->value == deserialized->value ? "OUI" : "NON") << std::endl;
    
    // Nettoyage
    delete original; // Attention : deserialized pointe vers la même adresse !
    
    return 0;
}