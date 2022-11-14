#ifndef BD2CA541_98C4_4849_A62D_96CF59CE311F
#define BD2CA541_98C4_4849_A62D_96CF59CE311F

#define INITIAL_VECTOR_SIZE 10
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

template <typename T>
class Vector{
    public:
        Vector();
        ~Vector();
        void add(T item);
    private:
        void resize();
        T *backing_array;
        int size;
};

#endif /* BD2CA541_98C4_4849_A62D_96CF59CE311F */
