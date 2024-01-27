#include <iostream>
#include <string>

class ContactNode {
public:
    std::string name;
    std::string phoneNumber;
    ContactNode* next;

    ContactNode(const std::string& contactName, const std::string& contactPhoneNumber)
        : name(contactName), phoneNumber(contactPhoneNumber), next(nullptr) {}
};

class ContactList {
private:
    ContactNode* head;

public:
    ContactList() : head(nullptr) {}

    // Function to add a new contact to the list
    void addContact(const std::string& name, const std::string& phoneNumber) {
        ContactNode* newContact = new ContactNode(name, phoneNumber);
        newContact->next = head;
        head = newContact;
        std::cout << "Contact added: " << name << std::endl;
    }

    // Function to delete a contact from the list
    void deleteContact(const std::string& name) {
        ContactNode* current = head;
        ContactNode* prev = nullptr;

        while (current != nullptr && current->name != name) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Contact not found: " << name << std::endl;
            return;
        }

        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
        std::cout << "Contact deleted: " << name << std::endl;
    }

    // Function to search for a contact in the list
    void searchContact(const std::string& name) {
        ContactNode* current = head;

        while (current != nullptr) {
            if (current->name == name) {
                std::cout << "Contact found: " << current->name << " - " << current->phoneNumber << std::endl;
                return;
            }
            current = current->next;
        }

        std::cout << "Contact not found: " << name << std::endl;
    }

    // Function to display all contacts in the list
    void displayContacts() {
        ContactNode* current = head;

        if (current == nullptr) {
            std::cout << "Contact list is empty." << std::endl;
            return;
        }

        std::cout << "Contact List:" << std::endl;
        while (current != nullptr) {
            std::cout << current->name << " - " << current->phoneNumber << std::endl;
            current = current->next;
        }
    }
};

int main() {
    ContactList contactList;

    // Adding contacts
    contactList.addContact("John Doe", "123-456-7890");
    contactList.addContact("Jane Smith", "987-654-3210");
    contactList.addContact("Alice Johnson", "555-123-4567");

    // Displaying contacts
    contactList.displayContacts();

    // Searching for a contact
    contactList.searchContact("Jane Smith");

    // Deleting a contact
    contactList.deleteContact("John Doe");

    // Displaying contacts after deletion
    contactList.displayContacts();

    return 0;
}
