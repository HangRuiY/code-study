using System;
namespace Lesson8_事件
{
    #region 事件
    //事件基于委托存在，让委托更安全
    //访问修饰符 event 委托类型 事件名
    //不能在类外部赋值，也不能在类外部调用
    //只能作为成员存在于 类和接口以及结构体中
    //目的：防止外部随意置空或调用委托，实际上就是封装委托
    #endregion
    #region 使用
    class Test
    {
        public Action myFun;//委托 用来存储函数
        public event Action myEvent;//事件 更安全的委托
        public Test()
        {
            myFun += TestFun1;
            myEvent += TestFun2;
            myFun();
            myEvent();
        }
        public void TestFun1()
        {
            Console.WriteLine("委托调用");
        }
        public void TestFun2()
        {
            Console.WriteLine("事件调用");
        }
        public void DoEvnet()
        {
            myEvent();
        }
    }
    #endregion
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        Test test = new Test();
    //        Console.WriteLine("*****");
    //        test.myFun += Func1;
    //        //test.myEvent = Func2;//不能在类外部赋值 但是可以+= -=
    //        //test.myEvent += Func2;
    //        test.myFun();
    //        //test.myEvent();//不能在类外部调用
    //        test.DoEvnet();
    //    }
    //    public static void Func1()
    //    {
    //        Console.WriteLine("委托调用2");
    //    }
    //    public static void Func2()
    //    {
    //        Console.WriteLine("事件调用2");
    //    }
    //}

    #region 事件练习 
    //热水器包含加热器和报警器还有显示器，当水温超过95度，1.报警器发出语音，告诉温度 2.显示器改变水温提示，提示水烧开了
    class HotWater
    {
        public event Action<HotWater> control;
        public int temp;
        public void Dosth(Alarm a,OLED o)
        {
            //加热过程
            //显示过程
            control += a.Heat;
            control += o.Look;
            control(this);
        }
        public void AddHot(Alarm a, OLED o)
        {
            Console.WriteLine("加热中...");
            int index = 0;
            while (true)
            {
                if (index % 9999999 == 0)
                {
                    temp++;
                    if (temp >= 95)
                    {
                        Dosth(a,o);
                        break;
                    }
                    index = 0;
                }
                index++;
            }
        }
    }
    class Alarm
    {
        public void Heat(HotWater h)
        {
            Console.WriteLine("发出警报:当前温度已经有{0}度",h.temp);
        }
    }
    class OLED
    {
        public void Look(HotWater h)
        {
            Console.WriteLine("当前温度:{0}度", h.temp);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            HotWater h = new HotWater();
            Alarm a = new Alarm();
            OLED o = new OLED();
            h.AddHot(a,o);
        }
    }
    #endregion
}