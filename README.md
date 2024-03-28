#Storage Manager for the Ultra Engine

Entity pointers can be managed with this class. I created this class because it often gets very confusing when you have complex relationships between different components and these have relationships with each other.

The class is intended to prevent pointers from being left alive unintentionally and all used pointers from being taken from a central pool. 

Instead of creating a variable for the pointer in a component, the entity can simply be added to the StorageManager. If you need an entity, you can simply retrieve it as weak_ptr and use it temporarily without hesitation. 

#How can the class be used? 

First create a global variable from the StorageManager. Then you can simply use 

```C
auto id = g_storage.AddEntity(entity);
```
to add an entity to the pool. The Storage Manager will return a uuid. However, you can also assign an id for the variable yourself. To do this, use 

```C
auto id2 = g_storage.AddEntity("test2", entity);
```
Note that AddEntity checks whether a pointer already exists in the pool. If this is the case, the ID of the existing element is adopted.

To get a variable from the StorageManager, you can simply use the following function

```C
auto e2 = g_storage.GetEntity(id).lock();
```
