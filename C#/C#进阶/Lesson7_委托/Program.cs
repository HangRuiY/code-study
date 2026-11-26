using System;
namespace Lesson7_委托
{
    #region 委托是什么
    //委托是函数的容器，可以认为是表示函数方法的变量类型，主要用来 存储 函数
    //本质上是一个类，用来定义函数的返回值和参数类型
    //不同的函数方法，必须对应和各自“格式”一致的委托
    #endregion
    #region 定义委托
    //定义一个委托 返回值int 参数int a
    //访问修饰符 delegate 返回值 委托名（参数列表） 就是函数语法的返回值能类型前加了delegate
    //可以写在class语句块和namespace中，更多的写在namespace在中
    //默认public
    delegate int MyFun(int a);//委托不能重载
    delegate void MyFun2();
    #endregion
    #region 使用委托
    //委托是函数的容器，常用在：1.类的成员 2.函数的参数
    //委托可以存储多个函数，用+=即可
    class Test
    {
        public MyFun fun;
        public MyFun2 fun2;
        public void TestFun(MyFun fun, MyFun2 fun2)
        {
            //委托的作用：先处理其他逻辑，然后再执行传入的函数
            int i = 1;
            i++; 
            this.fun = fun;
            this.fun2 = fun2;
        }
        //一个委托 可以存多个函数(多播委托)
        public void AddFun(MyFun fun, MyFun2 fun2)
        {
            this.fun += fun;
            this.fun2 += fun2;
        }
        public void SubFun(MyFun fun, MyFun2 fun2)
        {
            this.fun -= fun;
            this.fun2 -= fun2;
        }
    }
    #endregion
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        //常用的使用委托的语法
    //        MyFun f = Calc;
    //        Console.WriteLine(f(5));
    //        Console.WriteLine("******");
    //        //在类中使用委托
    //        Test t = new Test();
    //        t.TestFun(Calc,Func);//先存到成员变量中(也可以直接在成员函数中使用)
    //        Console.WriteLine(t.fun(5));//使用成员变量
    //        Console.WriteLine("******");
    //        //一个委托 可以存多个函数(多播委托)
    //        MyFun2 f2 = null;
    //        f2 += Func;
    //        f2 += Func2;
    //        f2();
    //        Console.WriteLine("******");
    //        t.AddFun(Calc, Func2);
    //        t.fun2();
    //        Console.WriteLine("******");
    //        //减去
    //        Test t2 = new Test();
    //        t2.AddFun(Calc, Func);
    //        t2.AddFun(Calc, Func2);
    //        t2.fun2();
    //        Console.WriteLine("******");
    //        t2.SubFun(Calc, Func2);
    //        t2.fun2();
    //        Console.WriteLine("******");
    //        #region 系统自带的委托
    //        //引用System命名空间
    //        //Action委托 存储无参无返回值的函数
    //        Action action = null;
    //        action += Func;
    //        action();
    //        //Func<>泛型委托 存储有返回值 无参的函数
    //        Func<string> func = Func3;
    //        Console.WriteLine(func());
    //        //Action<>泛型委托 存储无返回值 有参数的函数 <参数1，参数2...>
    //        Action<int, int> act = Func4;
    //        act(1, 2);
    //        //Func<>泛型委托 存储有返回值 有参数的函数
    //        Func<int, int> func2 = Calc;
    //        Console.WriteLine(func2(5));
    //        #endregion
    //    }
    //    static void Func4(int a,int b)
    //    {
    //        Console.WriteLine(a + b);
    //    }
    //    static string Func3()
    //    {
    //        return "123";
    //    }
    //    static int Calc(int a)
    //    {
    //        return a + 5;
    //    }
    //    static void Func()
    //    {
    //        Console.WriteLine("张三做什么");
    //    }
    //    static void Func2()
    //    {
    //        Console.WriteLine("李四做什么");
    //    }
    //}

    #region 委托练习1 一家三口，妈妈做饭，三人都吃饭
    abstract class Person
    {
        public abstract void Eat();
    }
    class Mother : Person
    {
        public Action beginEat;
        public override void Eat()
        {
            Console.WriteLine("妈妈吃饭");
        }
        public void Cook()
        {
            Console.WriteLine("妈妈做饭");
            //做饭的逻辑
            Console.WriteLine("妈妈做了菜和汤");
            //执行委托
            beginEat();
        }
    }
    class Father:Person
    {
        public override void Eat()
        {
            Console.WriteLine("爸爸吃饭");
        }
    }
    class Son : Person
    {
        public override void Eat()
        {
            Console.WriteLine("孩子吃饭");
        }
    }
    #endregion

    #region 委托练习2 怪物死亡，玩家加10块钱，界面更新数据，成就要累加怪物击杀数
    class Monster
    {
        //怪物死亡时，把自己作为参数传出去
        public Action<Monster> deadDosth;
        public int money = 10;
        public void Dead()
        {
            Console.WriteLine("怪物死亡");
            deadDosth(this);//怪物死亡 执行委托中的三个函数，参数是自身
        }
    }
    class Player
    {
        public bool flag = true;
        private int m_money = 0;
        public void Reward(Monster m)
        {
            if (!flag)
            {
                m_money = m_money;
                Console.WriteLine("无法再获得金钱，现在有{0}元", m_money);
            }
            else
            {
                m_money += m.money;
                Console.WriteLine("获得{0}元，共有{1}元", m.money, m_money);
            }
        }
    }
    class UI
    {
        public bool flag = true;
        private int showMoney = 0;
        public void MonsterDeadDo(Monster m)
        {
            if (!flag)
            {
                showMoney = showMoney;
                Console.WriteLine("当前拥有{0}元", showMoney);
            }
            else
            {
                showMoney += m.money;
                Console.WriteLine("当前拥有{0}元", showMoney);
            }
        }
    }
    class CJ
    {
        private int killNum = 0;
        public void MonsterDeadDo(Monster m)
        {
            killNum += 1;
            Console.WriteLine("当前击杀{0}个怪物", killNum);
        }
    }
    #endregion
    class Program
    {
        static void Main(string[] args)
        {
            //练习1
            //Mother m = new Mother();
            //Father f = new Father();
            //Son s = new Son();
            //m.beginEat += f.Eat;
            //m.beginEat += s.Eat;
            //m.beginEat += m.Eat;
            //m.Cook();

            //练习2
            Monster m = new Monster();
            Player p = new Player();    
            UI u = new UI();
            CJ cJ = new CJ();
            m.deadDosth += p.Reward;
            m.deadDosth += u.MonsterDeadDo;
            m.deadDosth += cJ.MonsterDeadDo;
            for(int i=1;i<=6 ;i++)
            {
                m.Dead();
                if (i>=4)
                {
                    p.flag = false;
                    u.flag = false ;
                }
            }
        }
    }
}