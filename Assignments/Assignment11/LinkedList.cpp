#include "LinkedList.h"

namespace LinkedList{

std::ostream& operator<<(std::ostream& os, const Node& node) {
    os << node.getValue();
    return os;
}

Node* LinkedList::insert(Node* pos, const std::string& value) {
    if(head.get() == pos) {
        head = std::make_unique<Node>(value, std::move(head), nullptr);
        pos->prev = head.get();
    }
    else {
        std::unique_ptr<Node> ourPtr = std::make_unique<Node>(value, std::move(pos->prev->next), pos->prev);
        pos->prev = ourPtr.get();
        pos->prev->next = move(ourPtr);
    }
    return pos->prev;
}

Node* LinkedList::remove(Node* pos) {
    if (pos->next.get() == tail) {
        pos->prev->next = move(pos->next);
        return pos->next.get();
    }
    else if (pos->prev == nullptr) {
        pos->next->prev = nullptr;
        pos->next = std::move(head);
        return head.get();
    }
    else {
        pos->prev->next = std::move(pos->next);
        pos->next->prev = pos->prev;
        return pos->next.get();
    }
}

Node* LinkedList::find(const std::string& value) {
    if (head->getValue() != value) {
        Node* currentPtr = head->next.get();
        while (currentPtr != tail) {
            if (currentPtr->getValue() == value) {
                return currentPtr;
            }
            else {
                currentPtr = currentPtr->next.get();
            }
        }
        return tail;
    }
    else {
        return head.get();
    }
}

void LinkedList::remove(const std::string& value) {
    remove(find(value));
}

std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
    auto currentPtr = list.begin();
    while (currentPtr != list.end()) {
        os << *currentPtr << '\n';
        currentPtr = currentPtr->getNext();
    }
    return os;
}
}

void testLinkedList() {
    LinkedList::LinkedList myList;
    myList.insert(myList.end(), "Potatoes");
    myList.insert(myList.begin(), "Carrots");
    myList.remove("Carrots");
    std::cout << myList;
}

// 3b)

// Lister kan endres på ganske lett så lenge man vet posisjonen på elementet som skal endres, mens
// en vektor er lett å lese av hvis man kan indeksen. Generelt er lister bedre å modulere på, mens vektorer
// er bedre å lese fra (altså bra for en konstant vektor).

// I en queue, går legges informasjon inn fra en side, og fjernes på den andre siden. Vi kan gjøre slik at 
// insert alltid vil sette inn fra for eksempel head, og remove fjerne fra tail.