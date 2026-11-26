using System;
namespace Lesson5_泛型约束
{
    #region 泛型约束
    //让泛型有限制 关键字是where
    //值类型:where 泛型字母:struct
    //引用类型: where 泛型字母:class
    //让泛型存在无参且public的构造函数: where 泛型字母:new()
    //某个类本身或者其派生类: where 泛型字母:类名
    //另一个泛型类型或者派生类型:where 泛型字母 泛型字母2
    class Test1<T> where T:struct
    {
        public T value;
        public void Test1Func<K>(K v) where K :struct
        {
            Console.WriteLine(v);
        }
    }
    #endregion

    #region 用泛型实现单例模式(一般用于管理器)基类
    class SingleBase<T> where T : new()
    {
        private static T instance = new T();
        public static T Instance
        {
            get { return instance; }
        }
    }
    class GameMgr : SingleBase<GameMgr>
    {
        public int value = 10;
        public GameMgr()
        {
             
        }
    }
    #endregion

    #region 仿造ArrayList实现不确定数组类型的类
    class ArrayList<T>
    {
        private T[] array;
        private int count;
        public ArrayList()
        {
            count = 0;
            array = new T[4];
        }
        public int Capacity
        {
            get
            {
                return array.Length;
            }
        }
        public int Count
        {
            get { return count; }
        }
        public void Add(T item)
        {
            //扩容
            if(count>=Capacity)
            {
                T[] newArray = new T[array.Length*2];
                for(int i=0;i<array.Length;i++)
                {
                    newArray[i] = array[i];
                }
                array = newArray;
            }
            array[count] = item;
            count++;
        }
        public void Remove(T item)
        {
            int index = -1;
            for(int i =0;i<count;i++)
            {
                //泛型不能用==判断，用object类中的equals判断
                if (array[i].Equals(item))
                {
                    index = i; break;
                }
            }
            if(index != -1)
            {
               RemoveAt(index); 
            }
        }
        public void RemoveAt(int index)
        {
            if(index < 0 || index >= Count)
            {
                return;
            }
            for (int i = index; i < count - 1; i++)
            {
                array[i] = array[i + 1];
            }
            array[count - 1] = default(T);
            count--;
        }
        public T this[int index]
        {
            get
            {
                return array[index];
            }
            set
            {
                array[index] = value;
            }
        }
    }
    #endregion
    class Program
    {
        static void Main(string[] args)
        {
            Test1<int> test1 = new Test1<int>();
            test1.Test1Func<char>('C');

            Console.WriteLine(GameMgr.Instance.value);

            ArrayList<int> array = new ArrayList<int>();
            Console.WriteLine(array.Count);
            Console.WriteLine(array.Capacity);
            array.Add(0);
            array.Add(1);
            array.Add(2);
            array.Add(3);
            array.Add(4);
            array.Add(5);
            Console.WriteLine(array.Count);
            Console.WriteLine(array.Capacity);
            Console.WriteLine(array[1]);
            array.Remove(0);
            array.RemoveAt(0);
            for (int i = 0; i < array.Count; i++)
            {
                Console.Write(array[i] + " ");
            }
            Console.WriteLine();
            array[0] = 99;
            for (int i = 0; i < array.Count; i++)
            {
                Console.Write(array[i] + " ");
            }
        }
    }
}