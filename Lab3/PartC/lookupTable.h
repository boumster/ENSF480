/*
 * File Name: lookupTable.h
 * Assignment: Lab 3 Exercise c
 * Completed by: Jaden Haug-Uhrin and Phoenix Bouma
 * Submission Date: Sept 27, 2024
 */
#ifndef LOOKUPTABLE_H
#define LOOKUPTABLE_H
#include <iostream>
using namespace std;

// class LookupTable: GENERAL CONCEPTS
//
//    key/datum pairs are ordered.  The first pair is the pair with
//    the lowest key, the second pair is the pair with the second
//    lowest key, and so on.  This implies that you must be able to
//    compare two keys with the < operator.
//
//    Each LookupTable has an embedded iterator class that allows users
//    of the class to traverse through the list and have access to each
//    node.

#include "customer.h"

//    In this version of the LookupTable a new struct type called Pair
//    is introduced which represents a key/data pair.

typedef int LT_Key;
typedef Customer LT_Datum;

template <typename KeyType, typename DatumType>
struct Pair {
  Pair(const KeyType& k, const DatumType& d) : key(k), datum(d) {}

  KeyType  key;
  DatumType datum;
};

// Templated Node class definition
template <typename KeyType, typename DatumType>
class LookupTable;

template <typename KeyType, typename DatumType>
class LT_Node {
  friend class LookupTable<KeyType, DatumType>;
private:
  Pair<KeyType, DatumType> pairM;
  LT_Node<KeyType, DatumType>* nextM;

 LT_Node(const Pair<KeyType, DatumType>& pairA, LT_Node<KeyType, DatumType>* nextA)
        : pairM(pairA), nextM(nextA) {}
};

template <typename KeyType, typename DatumType>
class LookupTable {
 public:

  // Nested class
  class Iterator {
    friend class LookupTable<KeyType, DatumType>;
    LookupTable<KeyType, DatumType> *LT;
  public:
    Iterator() : LT(0) {}
    Iterator(LookupTable<KeyType, DatumType> &x) : LT(&x) {}
    const DatumType& operator*();
    const DatumType& operator++();
    const DatumType& operator++(int);
    int operator!();

    void step_fwd() {
      assert(LT->cursor_ok());
      LT->step_fwd();
    }
  };

  LookupTable();
  LookupTable(const LookupTable<KeyType, DatumType> &source);
  LookupTable<KeyType, DatumType>& operator=(const LookupTable<KeyType, DatumType>& rhs);
  ~LookupTable();

  LookupTable<KeyType, DatumType>& begin();

  int size() const;
  int cursor_ok() const;

  const KeyType& cursor_key() const;
  const DatumType& cursor_datum() const;

  void insert(const Pair<KeyType, DatumType>& pairA);
  void remove(const KeyType& keyA);
  void find(const KeyType& keyA);
  void go_to_first();
  void step_fwd();
  void make_empty();

  template <typename K, typename D>
  friend ostream& operator<<(ostream& os, const LookupTable<K, D>& lt);

 private:
  int sizeM;
  LT_Node<KeyType, DatumType> *headM;
  LT_Node<KeyType, DatumType> *cursorM;

  void destroy();
  void copy(const LookupTable<KeyType, DatumType>& source);
};

#endif

template <typename KeyType, typename DatumType>
LookupTable<KeyType, DatumType>& LookupTable<KeyType, DatumType>::begin(){
  cursorM = headM;
  return *this;
}

// LookupTable Constructors/Destructors and methods
template <typename KeyType, typename DatumType>
LookupTable<KeyType, DatumType>::LookupTable()
  : sizeM(0), headM(0), cursorM(0) {}

template <typename KeyType, typename DatumType>
LookupTable<KeyType, DatumType>::LookupTable(const LookupTable<KeyType, DatumType>& source) {
  copy(source);
}

template <typename KeyType, typename DatumType>
LookupTable<KeyType, DatumType>& LookupTable<KeyType, DatumType>::operator=(const LookupTable<KeyType, DatumType>& rhs) {
  if (this != &rhs) {
    destroy();
    copy(rhs);
  }
  return *this;
}

template <typename KeyType, typename DatumType>
LookupTable<KeyType, DatumType>::~LookupTable() {
  destroy();
}

template <typename KeyType, typename DatumType>
int LookupTable<KeyType, DatumType>::size() const {
  return sizeM;
}

template <typename KeyType, typename DatumType>
int LookupTable<KeyType, DatumType>::cursor_ok() const {
  return cursorM != 0;
}

template <typename KeyType, typename DatumType>
const KeyType& LookupTable<KeyType, DatumType>::cursor_key() const {
  assert(cursor_ok());
  return cursorM->pairM.key;
}

template <typename KeyType, typename DatumType>
const DatumType& LookupTable<KeyType, DatumType>::cursor_datum() const {
  assert(cursor_ok());
  return cursorM->pairM.datum;
}

template <typename KeyType, typename DatumType>
void LookupTable<KeyType, DatumType>::insert(const Pair<KeyType, DatumType>& pairA) {
  if (headM == 0 || pairA.key < headM->pairM.key) {
    headM = new LT_Node<KeyType, DatumType>(pairA, headM);
    sizeM++;
  } else if (pairA.key == headM->pairM.key) {
    headM->pairM.datum = pairA.datum;
  } else {
    LT_Node<KeyType, DatumType>* before = headM;
    LT_Node<KeyType, DatumType>* after = headM->nextM;

    while (after != NULL && pairA.key > after->pairM.key) {
      before = after;
      after = after->nextM;
    }

    if (after != NULL && pairA.key == after->pairM.key) {
      after->pairM.datum = pairA.datum;
    } else {
      before->nextM = new LT_Node<KeyType, DatumType>(pairA, before->nextM);
      sizeM++;
    }
  }
}

template <typename KeyType, typename DatumType>
void LookupTable<KeyType, DatumType>::remove(const KeyType& keyA) {
  if (headM == 0 || keyA < headM->pairM.key)
    return;

  LT_Node<KeyType, DatumType> *doomed_node = 0;
  if (keyA == headM->pairM.key) {
    doomed_node = headM;
    headM = headM->nextM;
    sizeM--;
  } else {
    LT_Node<KeyType, DatumType> *before = headM;
    LT_Node<KeyType, DatumType> *maybe_doomed = headM->nextM;
    while (maybe_doomed != 0 && keyA > maybe_doomed->pairM.key) {
      before = maybe_doomed;
      maybe_doomed = maybe_doomed->nextM;
    }

    if (maybe_doomed != 0 && maybe_doomed->pairM.key == keyA) {
      doomed_node = maybe_doomed;
      before->nextM = maybe_doomed->nextM;
      sizeM--;
    }
  }
  delete doomed_node;
}

template <typename KeyType, typename DatumType>
void LookupTable<KeyType, DatumType>::find(const KeyType& keyA) {
  LT_Node<KeyType, DatumType> *ptr = headM;
  while (ptr != NULL && ptr->pairM.key != keyA) {
    ptr = ptr->nextM;
  }
  cursorM = ptr;
}

template <typename KeyType, typename DatumType>
void LookupTable<KeyType, DatumType>::go_to_first() {
  cursorM = headM;
}

template <typename KeyType, typename DatumType>
void LookupTable<KeyType, DatumType>::step_fwd() {
  assert(cursor_ok());
  cursorM = cursorM->nextM;
}

template <typename KeyType, typename DatumType>
void LookupTable<KeyType, DatumType>::make_empty() {
  destroy();
  sizeM = 0;
  cursorM = 0;
}

template <typename KeyType, typename DatumType>
void LookupTable<KeyType, DatumType>::destroy() {
  LT_Node<KeyType, DatumType> *ptr = headM;
  while (ptr != NULL) {
    headM = headM->nextM;
    delete ptr;
    ptr = headM;
  }
  cursorM = NULL;
  sizeM = 0;
}

template <typename KeyType, typename DatumType>
void LookupTable<KeyType, DatumType>::copy(const LookupTable<KeyType, DatumType>& source) {
    headM = nullptr;
    cursorM = nullptr;

    if (source.headM == nullptr)
        return;

    for (LT_Node<KeyType, DatumType>* p = source.headM; p != nullptr; p = p->nextM) {
        insert(Pair<KeyType, DatumType>(p->pairM.key, p->pairM.datum));
        if (source.cursorM == p) {
            find(p->pairM.key);
        }
    }
}

template <typename KeyType, typename DatumType>
ostream& operator<<(ostream& os, const LookupTable<KeyType, DatumType>& lt) {
  if (lt.cursor_ok())
    os << lt.cursor_key() << "  " << lt.cursor_datum();
  else
    os << "Not Found.";
  return os;
}

// Iterator Methods

template <typename KeyType, typename DatumType>
const DatumType& LookupTable<KeyType, DatumType>::Iterator::operator*() {
  assert(LT->cursor_ok());
  return LT->cursor_datum();
}

template <typename KeyType, typename DatumType>
const DatumType& LookupTable<KeyType, DatumType>::Iterator::operator++() {
  assert(LT->cursor_ok());
  const DatumType& x = LT->cursor_datum();
  LT->step_fwd();
  return x;
}

template <typename KeyType, typename DatumType>
const DatumType& LookupTable<KeyType, DatumType>::Iterator::operator++(int) {
  assert(LT->cursor_ok());
  LT->step_fwd();
  return LT->cursor_datum();
}

template <typename KeyType, typename DatumType>
int LookupTable<KeyType, DatumType>::Iterator::operator!() {
  return (LT->cursor_ok());
}
