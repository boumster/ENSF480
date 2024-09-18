/*
* File Name: dictionaryList.cpp
* Assignment: Lab 2 Exercise A
* Completed by: Jaden Haug-Uhrin and Phoenix Bouma
* Submission Date: Sept 20, 2024
*/
#include <assert.h>
#include <iostream>
#include <stdlib.h>
#include "dictionaryList.h"
#include "mystring_B.h"

using namespace std;

Node::Node(const Key& keyA, const Datum& datumA, Node *nextA)
  : keyM(keyA), datumM(datumA), nextM(nextA)
{
}

DictionaryList::DictionaryList()
  : sizeM(0), headM(0), cursorM(0)
{
}

DictionaryList::DictionaryList(const DictionaryList& source)
{
  copy(source);
}

DictionaryList& DictionaryList::operator =(const DictionaryList& rhs)
{
  if (this != &rhs) {
    destroy();
    copy(rhs);
  }
  return *this;
}

DictionaryList::~DictionaryList()
{
  destroy();
}

int DictionaryList::size() const
{
  return sizeM;
}

int DictionaryList::cursor_ok() const
{
  return cursorM != 0;
}

const Key& DictionaryList::cursor_key() const
{
  assert(cursor_ok());
  return cursorM->keyM;
}

Datum& DictionaryList::cursor_datum() const
{
  assert(cursor_ok());
  return cursorM->datumM;
}

void DictionaryList::insert(const int& keyA, const Mystring& datumA)
{
  // Add new node at head?
  if (headM == 0 || keyA < headM->keyM) {
    headM = new Node(keyA, datumA, headM);
    sizeM++;
  }

  // Overwrite datum at head?
  else if (keyA == headM->keyM)
    headM->datumM = datumA;

  // Have to search ...
  else {

    //POINT ONE

    // if key is found in list, just overwrite data;
    for (Node *p = headM; p !=0; p = p->nextM)
		{
			if(keyA == p->keyM)
			{
				p->datumM = datumA;
				return;
			}
		}

    //OK, find place to insert new node ...
    Node *p = headM ->nextM;
    Node *prev = headM;

    while(p !=0 && keyA >p->keyM)
		{
			prev = p;
			p = p->nextM;
		}

    prev->nextM = new Node(keyA, datumA, p);
    sizeM++;
  }
  cursorM = NULL;

}

void DictionaryList::remove(const int& keyA)
{
    if (headM == 0 || keyA < headM -> keyM)
        return;

    Node *doomed_node = 0;

    if (keyA == headM-> keyM) {
        doomed_node = headM;
        headM = headM->nextM;

        // POINT TWO
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->nextM;
        while(maybe_doomed != 0 && keyA > maybe_doomed-> keyM) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->nextM;
        }

        if (maybe_doomed != 0 && maybe_doomed->keyM == keyA) {
            doomed_node = maybe_doomed;
            before->nextM = maybe_doomed->nextM;
        }


    }
    if(doomed_node == cursorM)
        cursorM = 0;

    delete doomed_node;           // Does nothing if doomed_node == 0.
    sizeM--;
}

void DictionaryList::go_to_first()
{
    cursorM = headM;
}

void DictionaryList::step_fwd()
{
    assert(cursor_ok());
    cursorM = cursorM->nextM;
}

void DictionaryList::make_empty()
{
    destroy();
    sizeM = 0;
    cursorM = 0;
}


// The following function are supposed to be completed by the stuents, as part
// of the exercise B part II. the given fucntion are in fact place-holders for
// find, destroy and copy, in order to allow successful linking when you're
// testing insert and remove. Replace them with the definitions that work.

void DictionaryList::find(const Key& keyA)
{
  cout << "\nDon't know how to find " << keyA << " (or any other key).\n";
  cout << "... so exit is being called.\n";
  exit(1);
}


void DictionaryList::destroy()
{
  cout << "\nWARNING: DictionaryList::destroy() is abandoning nodes\n"
       << "when it should be deleting them!\n";
  headM = 0;
}


void DictionaryList::copy(const DictionaryList& source)
{
    destroy();

    if (source.headM == nullptr) {
        headM = nullptr;
    } else {
        headM = new Node(source.headM->keyM, source.headM->datumM, nullptr);
        Node* current = headM;
        Node* sourceNode = source.headM->nextM;

        while (sourceNode != nullptr) {
            current->nextM = new Node(sourceNode->keyM, sourceNode->datumM, nullptr);
            current = current->nextM;
            sourceNode = sourceNode->nextM;
        }
    }
}

std::ostream& operator <<(std::ostream& out, const DictionaryList& dl) {
    // Ensure list is not empty
    if (dl.sizeM == 0) {
        out << "List is EMPTY.\n";
        return out;
    }

    Node* current = dl.headM;
    while (current != nullptr) {
        out << current->keyM << "  " << current->datumM << '\n';
        current = current->nextM;
    }
    return out;
}

Datum& DictionaryList::operator[](int index) {
    Node* current = headM;
    int currentIndex = 0;

    // Find node at wanted index
    while (current != nullptr && currentIndex < index) {
        current = current->nextM;
        currentIndex++;
    }

    return current->datumM; // Return the datum of the found node
}


