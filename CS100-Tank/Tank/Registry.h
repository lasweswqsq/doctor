#pragma once

/// \file
/// \brief This file introduces a registry that helps us
/// manage instances of a `struct`.
/// Please read the following examples to understand how it works.
///
/// \note Don't worry, you are not forced to understand the codes, since
/// the implementation is a little bit complex and contains "black magics".
/// Just read the following examples and feel free to do your homework with it.
/// We hope you will enjoy the magics, OwO.
///
/// \example This example shows how to use registry to handle stack memory.
/// ```c
/// #include "Registry.h"
///
/// typedef struct {
///   TK_REG_AUTH;
///   int bar;
/// } Foo;
///
/// static TK_REG_DEF(Foo, regFoo);
///
/// int main(void) {
///   RegInit(regFoo);
///
///   Foo foo0 = {.bar = 233};
///   Foo foo1 = {.bar = 466};
///
///   RegAdd(regFoo, &foo0);
///   RegAdd(regFoo, &foo1);
///   printf("Number of registered instances: %d\n", (int)RegSize(regFoo)); // Should be `2`.
///
///   for (RegIterator it = RegBegin(regFoo); it != RegEnd(regFoo); it = RegNext(it)) {
///     Foo *foo = RegEntry(regFoo, it);
///     printf("Value: %d\n", foo->bar);
///   }
///
///   RegRemove(&foo0);
///   RegRemove(&foo1);
///   printf("Number of registered instances: %d\n", (int)RegSize(regFoo)); // Should be `0`.
///
///   return 0;
/// }
/// ```
///
/// \example This example shows how to use registry to handle heap memory.
/// ```c
/// #include "Registry.h"
///
/// typedef struct {
///   TK_REG_AUTH;
///   int bar;
/// } Foo;
///
/// static TK_REG_DEF(Foo, regFoo);
///
/// int main(void) {
///   RegInit(regFoo);
///
///   Foo *foo0 = malloc(sizeof(Foo));
///   Foo *foo1 = malloc(sizeof(Foo));
///   foo0->bar = 233;
///   foo1->bar = 466;
///
///   RegAdd(regFoo, foo0);
///   RegAdd(regFoo, foo1);
///   printf("Number of registered instances: %d\n", (int)RegSize(regFoo)); // Should be `2`.
///
///   while (RegSize(regFoo) > 0) {
///     Foo *foo = RegEntry(regFoo, RegBegin(regFoo));
///     printf("Value: %d\n", foo->bar);
///     RegRemove(foo);
///     free(foo);
///   }
///   printf("Number of registered instances: %d\n", (int)RegSize(regFoo)); // Should be `0`.
///
///   return 0;
/// }
/// ```
///
/// \example This example shows how to use registry to handle heap arrays.
/// ```c
/// #include "Registry.h"
///
/// typedef struct {
///   TK_REG_AUTH;
///   int bar;
/// } Foo;
///
/// static TK_REG_DEF(Foo, regFoo);
///
/// int main(void) {
///   RegInit(regFoo);
///
///   const int n = 5;
///   Foo *foos = malloc(sizeof(Foo) * n);
///   for (int i = 0; i < n; ++i) {
///     foos[i].bar = i * 233;
///     RegAdd(regFoo, &foos[i]);
///   }
///   printf("Number of registered instances: %d\n", (int)RegSize(regFoo)); // Should be `5`.
///
///   for (RegIterator it = RegBegin(regFoo); it != RegEnd(regFoo); it = RegNext(it)) {
///     Foo *foo = RegEntry(regFoo, it);
///     printf("Value: %d\n", foo->bar);
///   }
///
///   while (RegSize(regFoo) > 0)
///     RegRemove(RegEntry(regFoo, RegBegin(regFoo)));
///   free(foos);
///   printf("Number of registered instances: %d\n", (int)RegSize(regFoo)); // Should be `0`.
///
///   return 0;
/// }
/// ```
///
/// \example This example shows how `RegNew` and `RegDelete` make life even easier.
/// ```c
/// #include "Registry.h"
///
/// typedef struct {
///   TK_REG_AUTH;
///   int bar;
/// } Foo;
///
/// static TK_REG_DEF(Foo, regFoo);
///
/// int main(void) {
///   RegInit(regFoo);
///
///   Foo *foo0 = RegNew(regFoo); //! `malloc` is called here.
///   Foo *foo1 = RegNew(regFoo);
///   foo0->bar = 233;
///   foo1->bar = 466;
///   printf("Number of registered instances: %d\n", (int)RegSize(regFoo)); // Should be `2`.
///
///   while (RegSize(regFoo) > 0) {
///     Foo *foo = RegEntry(regFoo, RegBegin(regFoo));
///     printf("Value: %d\n", foo->bar);
///     RegDelete(foo); //! `free` is called here.
///   }
///   printf("Number of registered instances: %d\n", (int)RegSize(regFoo)); // Should be `0`.
///
///   return 0;
/// }
/// ```
///
/// \details If you are curious about how it is implemented, please
/// refer to the following materials:
/// 1. `list.h` and `list.c` of Pintos, see https://en.wikipedia.org/wiki/Pintos.
/// 2. The book "Hands-On Design Patterns with C++", Chapter 8: The Curiously Recurring Template Pattern (CRTP).
/// 3. A C++ implementation: https://github.com/Nagisaaaaaaaaa/ARIA/blob/main/ARIA/Core/Core/include/ARIA/Registry.h.

//
//
//
//
//
#include "Base.h"

typedef struct __TK_RegElem {
  struct __TK_RegElem *prev;
  struct __TK_RegElem *next;
} RegElem;

typedef struct {
  RegElem head;
  RegElem tail;
} Reg;

/// \brief A `RegIterator` helps iterate through a registry.
///
/// \example ```c
/// RegIterator it = RegBegin(regFoo);
/// ```
///
/// \see RegBegin
/// \see RegEnd
/// \see RegNext
typedef RegElem *RegIterator;

/// \brief Authorize a `struct` to make it compatible with registries.
///
/// \example ```c
/// typedef struct {
///   TK_REG_AUTH; // This line of code performs the authorization.
///   int bar;
/// } Foo;
/// ```
#define TK_REG_AUTH RegElem __TK_regElem

/// \brief Instantiate a registry whose name is `reg` and element type is `type`.
///
/// \example ```c
/// static TK_REG_DEF(Foo, regFoo); // Instantiate a static registry.
/// TK_REG_DEF(Foo, regFoo);        // Instantiate a local registry.
/// ```
#define TK_REG_DEF(type, reg)                                                                                          \
  Reg reg;                                                                                                             \
  typedef type TK_CONCAT(__TK_RegType_, reg);                                                                          \
  static type TK_CONCAT(__TK_regTypeInstance, reg);                                                                    \
  static_assert(sizeof(TK_CONCAT(__TK_regTypeInstance, reg).__TK_regElem) > 0,                                         \
                "The given type has not been authorized with `TK_REG_AUTH`")

/// \brief Get the instance pointed by the iterator.
///
/// \example ```c
/// RegIterator it = RegBegin(regFoo);
/// Foo *foo = RegEntry(regFoo, it);
/// ```
///
/// \see RegIterator
#define RegEntry(reg, iterator)                                                                                        \
  ((TK_CONCAT(__TK_RegType_, reg) *)((uint8_t *)&(iterator)->next -                                                    \
                                     offsetof(TK_CONCAT(__TK_RegType_, reg), __TK_regElem.next)))

//
//
//
// Checks whether `elem` is the head.
static inline bool __TK_RegIsHead(RegElem *elem) {
  return elem != NULL && elem->prev == NULL && elem->next != NULL;
}

// Checks whether `elem` is an interior element.
static inline bool __TK_RegIsInterior(RegElem *elem) {
  return elem != NULL && elem->prev != NULL && elem->next != NULL;
}

// Checks whether `elem` is the tail.
static inline bool __TK_RegIsTail(RegElem *elem) {
  return elem != NULL && elem->prev != NULL && elem->next == NULL;
}

//
//
//
void __TK_RegInit(Reg *reg) {
  TK_ASSERT(reg != NULL);
  reg->head.prev = NULL;
  reg->head.next = &reg->tail;
  reg->tail.prev = &reg->head;
  reg->tail.next = NULL;
}

/// \brief Initialize the registry.
///
/// \example ```c
/// RegInit(regFoo);
/// ```
#define RegInit(reg) __TK_RegInit(&(reg))

//
//
//
RegElem *__TK_RegBegin(Reg *reg) {
  TK_ASSERT(reg != NULL);
  return reg->head.next;
}

/// \brief Get the begin iterator of the registry.
///
/// \example ```c
/// RegIterator it = RegBegin(regFoo);
/// ```
#define RegBegin(reg) __TK_RegBegin(&(reg))

RegElem *__TK_RegEnd(Reg *reg) {
  TK_ASSERT(reg != NULL);
  return &reg->tail;
}

/// \brief Get the end iterator of the registry.
///
/// \example ```c
/// RegIterator it = RegEnd(regFoo);
/// ```
#define RegEnd(reg) __TK_RegEnd(&(reg))

/// \brief Get the iterator pointing to the next instance.
///
/// \example ```c
/// it = RegNext(it);
/// ```
RegElem *RegNext(RegElem *elem) {
  TK_ASSERT(__TK_RegIsHead(elem) || __TK_RegIsInterior(elem));
  return elem->next;
}

//
//
//
size_t __TK_RegSize(Reg *reg) {
  size_t res = 0;
  for (RegIterator it = RegBegin(*reg); it != RegEnd(*reg); it = RegNext(it))
    ++res;
  return res;
}

/// \brief Get number of registered instances.
///
/// \example ```c
/// size_t n = RegSize(regFoo);
/// ```
#define RegSize(reg) __TK_RegSize(&(reg))

//
//
//
void __TK_RegAdd(Reg *reg, RegElem *elem) {
  TK_ASSERT(reg != NULL);
  TK_ASSERT(elem != NULL);
  RegElem *end = RegEnd(*reg);

  elem->prev = end->prev;
  elem->next = end;
  end->prev->next = elem;
  end->prev = elem;
}

/// \brief Add an instance to the registry.
///
/// \example ```c
/// Foo foo = {.bar = 233};
/// RegAdd(regFoo, &foo);
/// ```
#define RegAdd(reg, ptr)                                                                                               \
  do {                                                                                                                 \
    TK_CONCAT(__TK_RegType_, reg) typeChecker = *ptr;                                                                  \
    static_assert(sizeof(typeChecker.__TK_regElem) > 0, "The given type has not been authorized with `TK_REG_AUTH`");  \
    __TK_RegAdd(&(reg), &(ptr)->__TK_regElem);                                                                         \
  } while (0)

RegElem *__TK_RegRemove(RegElem *elem) {
  TK_ASSERT(__TK_RegIsInterior(elem));

  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  return elem->next;
}

/// \brief Remove an instance from its corresponding registry.
///
/// \example ```c
/// RegRemove(&foo);
/// ```
#define RegRemove(ptr) __TK_RegRemove(&(ptr)->__TK_regElem)

//
//
//
static void *__TK_regTempPtr = NULL;

/// \brief Allocate memory for an instance and add it to the registry.
///
/// \example ```c
/// Foo *foo = RegNew(regFoo); //! `malloc` is called here.
/// ```
#define RegNew(reg)                                                                                                    \
  (__TK_regTempPtr = malloc(sizeof(TK_CONCAT(__TK_RegType_, reg))),                                                    \
   __TK_RegAdd(&(reg), &((TK_CONCAT(__TK_RegType_, reg) *)__TK_regTempPtr)->__TK_regElem),                             \
   (TK_CONCAT(__TK_RegType_, reg) *)__TK_regTempPtr)

/// \brief Remove an instance from its corresponding registry and free its memory.
///
/// \example ```c
/// RegDelete(foo); //! `free` is called here.
/// ```
#define RegDelete(ptr)                                                                                                 \
  do {                                                                                                                 \
    __TK_regTempPtr = ptr;                                                                                             \
    RegRemove(ptr);                                                                                                    \
    free(__TK_regTempPtr);                                                                                             \
    /*ptr = NULL;*/ /* This line of code only works for l-values. */                                                   \
  } while (0)
