using System;
namespace Lesson6_存储结构
{
    #region List-泛型数组
    #endregion

    #region Dictionary-泛型哈希表
    #endregion

    #region LinkedList - 泛型双向链表
    #endregion

    #region 数据结构
    //数据结构就是计算机组织，存储数据的规则
    //数据结构就是具有一种或多种联系的数据的集合，简单来说就是人定义的 存储数据 和 表示数据之间关系 的规则
    #endregion

    #region 线性表
    //多个相同特性的元素组成的有序序列
    //数组，ArrayList,Queue,Stack,链表
    #endregion

    #region 顺序存储
    //用地址连续的存储单元 依次存储线性元素（线性表的元素），难扩容
    //数组，ArrayList,Queue,Stack,List（泛型数组）
    #endregion

    #region 链式存储
    //用一组任意的存储单元，存储线性表元素
    //单向链表，双向链表，循环链表
    #endregion

    #region 顺序存储和链式存储的优缺点
    //从增删查改的角度去思考
    //增:链式存储 计算上 优于顺序存储(中间插入时链式不用像顺序一样去移动位置)
    //删:链式存储 计算上 优于顺序存储(中间删除时链式不用像顺序一样去移动位置)
    //查:顺序存储 使用上 优于链式存储(数组可以直接通过下标得到元素, 链式需要遍历)
    //改:顺序存储 使用上 优于链式存储(数组可以直接通过下标得到元素, 链式需要遍历)
    #endregion

    #region 复杂数据容器
    //枚举 enum
    //结构体 struct
    //数组(一维、二维、交错)[][,][][]
    //类
    #endregion

    #region 数据集合
    //using System.Collections;
    //ArrayList object数据列表
    //Stack 栈 先进后出
    //Queue 队列 先进先出
    //Hashtable 哈希表 键值对
    #endregion

    #region 泛型数据集合
    //using System.Collections.Generic;
    //List 列表 泛型列表
    //Dictionary 字典 泛型哈希表
    //LinkedList 双向链表
    //Stack<> 泛型栈
    //Queue<> 泛型队列
    #endregion

    #region 如何选择
    //普通线性表:
    //数组,List,LinkedList
    //数组:固定的不变的一组数据
    //List:经常改变,经常通过下标查找
    //LinkedList:不确定长度的,经常临时插入改变,查找不多

    //先进后出:
    //Stack
    //对于一些可以利用先进后出存储特点的逻辑
    //比如:UI面板显隐规则

    //先进先出:
    //Queue
    //对于一些可以利用先进先出存储特点的逻辑
    //比如:消息队列,有了就往里放,然后慢慢依次处理

    //键值对:
    //Dictionary
    //需要频繁查找的,有对应关系的数据
    //比如一些数据存储 id对应数据内容
    //道具ID一>道具信息
    //怪物ID一>怪物对象
    #endregion

    #region 单链表
    class LinkNode
    {
        public int value;
        public LinkNode nextnode;
        public LinkNode(int value)
        {
            this.value = value; this.nextnode = null;
        }
    }
    class LinkTest
    {
        public LinkNode head;
        public LinkNode tail;

        public void Add(int value)
        {
            LinkNode node = new LinkNode(value);
            if(head == null)
            {
                head = node;
                tail = node;
            }
            else
            {
                tail.nextnode = node;
                tail = node;
            }
        }
        public void Remove(int value)
        {
            if(head.value == value)
            {
                head = head.nextnode;
                if(head==null)
                {
                    tail = null;
                }
                return;
            }
            LinkNode node = head;
            while(node.nextnode!=null)
            {
                if(node.value==value)
                {
                    node.nextnode = node.nextnode.nextnode;
                    node = node.nextnode;
                    break;
                }
            }

        }
    }
    #endregion

    #region 双向链表
    class LinkedNode<T>
    {
        public T value;
        public LinkedNode<T> frontNode;
        public LinkedNode<T> nextNode;
        public LinkedNode(T value)
        {
            this.value = value;
        }
    }
    class LinkedList<T>
    {
        private int count = 0;
        private LinkedNode<T> head;
        private LinkedNode<T> last;
        public int Count
        {
            get
            {
                return count;
            }
        }
        public LinkedNode<T> Head
        {
            get
            {
                return head;
            }
        }
        public LinkedNode<T> Last
        {
            get
            {
                return last;
            }
        }
        public void Add(T value)
        {
            //新加节点
            LinkedNode<T> node = new LinkedNode<T>(value);
            if (head == null)
            {
                head = node;
                last = node;
            }
            else
            {
                //添加到尾部
                last.nextNode = node;
                //尾部添加的节点 记录自己的上一个节点是谁
                node.frontNode = last;
                //让当前新加的变成最后一个节点
                last = node;
            }
            //加了一个节点
            ++count;
        }
        public void RemoveAt(int index)
        {
            //首先判断 有没有越界
            if (index >= count || index < 0)
            {
                Console.WriteLine("只有{0}个节点，请输入合法位置", count);
                return;
            }
            int tempCount = 0;
            LinkedNode<T> tempNode = head;
            while (true)
            {
                //找到了对应位置的节点 然后移除即可
                if (tempCount == index)
                {
                    //当前要移除的节点的上一个节点 指向自己的下一个节点
                    if (tempNode.frontNode != null)
                    {
                        tempNode.frontNode.nextNode = tempNode.nextNode;
                    }
                    if (tempNode.nextNode != null)
                    {
                        tempNode.nextNode.frontNode = tempNode.frontNode;
                    }
                    //如果是头节点 那需要改变头节点的指向
                    if (index == 0)
                    {
                        //如果头节点被移除 那头节点就变成了头节点的下一个
                        head = head.nextNode;
                    }
                    else if (index == count - 1)
                    {
                        //如果尾节点被移除了 那尾结点就变成了尾结点的上一个
                        last = last.frontNode;
                    }
                    //移除了一个元素 就应该短一截
                    --count;
                    break;
                }
                //每次循环完过后 要让当前临时节点 等于下一个节点
                tempNode = tempNode.nextNode;
                ++tempCount;
            }
        }
    }
    #endregion

    class Program
    {
        static void Main(string[] args)
        {
            //LinkTest link = new LinkTest();
            //link.Add(1);
            //link.Add(2);
            //link.Add(3);
            //link.Add(4);
            //LinkNode node = link.head;
            //while(node!=null)
            //{
            //    Console.WriteLine(node.value);
            //    node = node.nextnode;
            //}
            //link.Remove(1);
            //link.Remove(2);
            //node = link.head;
            //while (node != null)
            //{
            //    Console.WriteLine(node.value);
            //    node = node.nextnode;
            //}

            LinkedList<int> link = new LinkedList<int>();
            link.Add(1);
            link.Add(2);
            link.Add(3);
            link.Add(4);
            //正向遍历
            LinkedNode<int> node = link.Head;
            while (node != null)
            {
                Console.WriteLine(node.value);
                node = node.nextNode;
            }
            //反向遍历
            node = link.Last;
            while (node != null)
            {
                Console.WriteLine(node.value);
                node = node.frontNode;
            }
            link.RemoveAt(0);
            //正向遍历
            node = link.Head;
            while (node != null)
            {
                Console.WriteLine(node.value);
                node = node.nextNode;
            }
            //反向遍历
            node = link.Last;
            while (node != null)
            {
                Console.WriteLine(node.value);
                node = node.frontNode;
            }
            Console.WriteLine("***************");
            link.RemoveAt(1);
            //正向遍历
            node = link.Head;
            while (node != null)
            {
                Console.WriteLine(node.value);
                node = node.nextNode;
            }
            //反向遍历
            node = link.Last;
            while (node != null)
            {
                Console.WriteLine(node.value);
                node = node.frontNode;
            }
            Console.WriteLine("***************");
            link.RemoveAt(1);
            //正向遍历
            node = link.Head;
            while (node != null)
            {
                Console.WriteLine(node.value);
                node = node.nextNode;
            }
            //反向遍历
            node = link.Last;
            while (node != null)
            {
                Console.WriteLine(node.value);
                node = node.frontNode;
            }
            Console.WriteLine("***************");
        }
    }
}