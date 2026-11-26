using System;
using System.Collections;
using static System.Net.Mime.MediaTypeNames;
namespace Lesson4_泛型
{
    #region 泛型是什么
    //实现类型参数化，目的是重用代码
    //泛型就是类型占位符
    //在<>里面写的类型，就是声明变量时，变量的类型，多变性
    #endregion
    #region 泛型分类
    //泛型类和泛型接口
    //class 类名<泛型占位字母>
    //interface 接口名<泛型占位字母>
    //继承泛型类或者泛型接口时，必须在<>里面写明类型
    //泛型函数
    //函数名<泛型占位字母>
    //泛型占位字母可以有多个
    class Test<T1, T2>
    {
        public T1 value1;
        public T2 value2;
    }
    #endregion

    #region 泛型方法
    class Test2
    {
        public T TestFunc<T>(T str)
        {
            return str;
        }
    }
    #endregion

    #region 泛型作用
    //不同类型对象的相同逻辑处理可以使用泛型
    //一定程度减少装箱拆箱
    //比如优化ArrayList，让增加和减少元素 可以少进行类型转换
    class ArrayList<T>
    {
        private T[] array;
        public void Add(T item)
        {

        }
    }
    #endregion

    class Program
    {
        static void Main(string[] args)
        {
            Test<int, Test<int, string>> t = new Test<int, Test<int, string>>();
            t.value1 = 1;
            t.value2 = new Test<int, string>();
            t.value2.value1 = 2;
            t.value2.value2 = "123";

            Test2 t2 = new Test2();
            string str = t2.TestFunc<string>("123");
            Console.WriteLine(str);

            Console.Write(Fun<int>());
        }
        static string Fun<T>()
        {
            if(typeof(T)==typeof(int))
            {
                return string.Format("{0}，{1}字节","整形",sizeof(int));
            }
            return "其他类型";
        }
    }
}