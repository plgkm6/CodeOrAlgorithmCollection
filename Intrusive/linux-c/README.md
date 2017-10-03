[1]: http://blog.chinaunix.net/uid-28458801-id-4250240.html

源码来源：[ linux下双向链表的实现][1]

+ 重点：

``` c
//得到@member基于@struct_t（地址0）的偏移量
#define __offsetof(struct_t, member) ((size_t)&((struct_t*)0)->member)
//根据@ptr（struct_t->member)和__offsetof得到ptr结构体的首地址（指针）
#define __container_of(ptr, struct_t, member) \
({ \
const typeof(((struct_t*)0)->member) *__mptr = (ptr); \
(struct_t*)((char*)__mptr - __offsetof(struct_t, member)); \
})

//get the struct(include list_head) for this entry
#define get_list_entry(ptr, struct_t, member) __container_of(ptr, struct_t, member)

//get the first element from a list
#define get_list_first_entry(ptr, struct_t, member) get_list_entry((ptr)->next, struct_t, member)
```

+ 详解：

1 __offsetof: 将0地址强制转换为struct_t类型（linux下是允许的），然后就用size_t强制转换得到struct->member的偏移量（基于0地址的），设为offset；

2 __container_of: 首先再次用上面的方法，得到struct_t->member的类型，并用它声明一个指针（__mptr）并指向传入参数ptr（struct_t->member实例的指针），然后转化为地址，减去上面得到的offset（struct_t->member*实例的地址*减去*基于0的偏移*），就可以得到struct_t实例的实际地址了。
