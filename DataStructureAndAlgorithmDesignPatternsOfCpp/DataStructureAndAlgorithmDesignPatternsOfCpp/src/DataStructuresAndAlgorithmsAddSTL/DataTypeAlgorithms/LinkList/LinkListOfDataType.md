
1. list和vector的区别（增删改查）
   1.1. 根本的不同就是内存存储方式不同，vector是连续的存储，list是通过指针连接，内存块是可以不连续的。
   1.2. 所以vector可以使用[],at来随机访问元素（可以访问指定位置元素），[]不会抛出异常，而at会因为指定位置超出容量从而抛出异常；list只能通过指针（迭代器）来访问。那么在指定位置的“改查”，vector就有优势。所以在使用的时候，如果是比较侧重随机访问的场景就用vector
   1.3. 因为存储方式不一样，插入与删除（增删）则是list优势明显，因为list只要将对应的指针指向指定地址就可以了，而vector需要copy，析构元素，这是比较大的开销，会影响vector效率。
   1.4. 同样因为内存的存储方式不一样，所以如果是在比较频繁扩容的操作中，vector需要承担这部分开销，效率没有list高。
2. 创建list中头插法与尾插法
   注：我个人对尾插法更加偏爱，更加容易理解(容易记住)，详细源码在CLinkList.cpp的构造函数里面。
   2.1. 头插法
        m_firstNode = new chainNode(0, nullptr);
        LinkListNode NewNode;
        for (int i = iInitialSize - 1; i != 0; i--)
		{
			NewNode = new chainNode(i, nullptr);
			NewNode->m_next = m_firstNode->m_next;
			m_firstNode->m_next = NewNode;
		}
   2.2. 尾插法
    这里就详细说下尾插法：设m_firstNode的地址是[oxfd(0,0000)],qTestNode的地址是[oxqd(0,0000)],newNode1，newNode2的地址是[oxd1(1，0000)]，[oxd2(2，0000)]...
         m_firstNode = new chainNode(0, nullptr);
         LinkListNode NewNode;
         LinkListNode qTestNode = m_firstNode;
		 for (int i = 1; i != iInitialSize; i++)
		{
			NewNode = new chainNode(i, nullptr);
			qTestNode->m_next = NewNode;
			qTestNode = NewNode;
		}
        1) m_firstNode = new chainNode(0, nullptr);得到[oxfd(0,0000)]
        2) LinkListNode qTestNode = m_firstNode;赋值qd得到[oxfd(0,0000)]
        3) NewNode = new chainNode(i, nullptr);得到nd1[oxd1(1，0000)]
        4) qTestNode->m_next = NewNode;将oxd1赋值给qd（oxfd）指向的0000，那么这个时候qd指向的就变成了[oxfd(0,oxd1)],而[oxd1(1,0000)]
        5) qTestNode = NewNode;那么qt的指向就变成了[oxd1(1,0000)],等待下一个循环，fd指向没有变[oxfd(0,oxd1)],而[oxd1(1,0000)]
	
3. list指向下一个
   currentNode = currentNode->m_next;（不要写反了）
   

