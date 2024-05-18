// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  first->prev = nullptr;
  first = new Cage;
  iLen = 0;
  iRes = 0;
  countOp = 0;
}

void Train::addCage(bool light) {
  if (first->prev != nullptr) {
    Cage *cTemp = first->next;
    first->next = new Cage;
    first = first->next;
    first->next->prev = first;
    first->next = cTemp;
    first->light = light;
    cTemp->prev = first;
  } else if (first->prev == nullptr) {
    first->prev = first;
    first->next = first;
    first-> light = light;
  }
}

int Train::getLength() {
  if (!first->light) {
    first->light = true;
  }
  while (true) {
    while (!first->next->light) {
      countOp = countOp + 1;
      iLen = iLen + 1;
      first = first->next;
    }
    countOp = countOp + 2;
    first->next->light = false;
    iRes = iLen + 1;
    for (; iLen > 0; iLen--) {
      first = first->prev;
      countOp++;
    }
    if (first->light == false)
      break;
  }
  return iRes;
}

int Train::getOpCount() {
  return countOp;
}
