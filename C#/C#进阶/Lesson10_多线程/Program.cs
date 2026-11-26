using System.ComponentModel;
using System.Drawing;
namespace Lesson10_多线程
{
    //class Program
    //{
    //    static Object obj = new Object();
    //    static void Main(string[] args)//主线程
    //    {
    //        #region 进程和线程
    //        //process 打开一个应用程序就等价于开启一个进程
    //        //进程之间可以相互访问 也可以 独立运行
    //        //线程包含在进程中，是进程的实际运作单位，一个进程中可以并发多个线程
    //        //我们写的程序都在 主线程中  最终的应用程序是进程，但是编写的都是线程
    //        #endregion
    //        #region 新线程
    //        //1.线程执行的代码，需要封装到函数中，即参数是委托类型
    //        Thread t = new Thread(NewThread);

    //        //2.开启线程
    //        t.Start();

    //        //3.将自己的新线程设置为后台线程
    //        //前台线程结束后，整个程序也就结束，即使后台线程仍在运行
    //        //如果不设置为后台线程，整个进程可能无法关闭
    //        //t.IsBackground = true;

    //        //4.关闭释放一个线程
    //        //如果不是死循环，不用刻意关闭
    //        //如果是，那么/
    //        //4.1死循环中加结束Bool标识
    //        //Console.ReadKey();
    //        //isRun = false;
    //        //Console.ReadKey();
    //        //4.2通过线程提供的方法进行关闭
    //        //t.Abort();
    //        //t = null;

    //        //5.线程休眠
    //        //在哪个线程里sleep 就休眠哪个线程 单位是毫秒
    //        //Thread.Sleep(1000);
    //        #endregion

    //        #region 线程之间共享数据
    //        //多个线程之间使用的内存空间是共享的，都属于一个进程
    //        //通过加锁，让多线程之间独立访问内存空间
    //        //lock(引用类型对象)
    //        while(true)
    //        {
    //            lock (obj)
    //            {
    //                Console.SetCursorPosition(0, 0);
    //                Console.ForegroundColor = ConsoleColor.Green;
    //                Console.Write("●");
    //            }
    //        }
    //        #endregion

    //        #region 多线程作用
    //        //处理复杂耗时的逻辑
    //        //游戏寻路系统
    //        #endregion
    //    }
    //    static bool isRun = true;
    //    static void NewThread()
    //    {
    //        //新线程执行的代码逻辑
    //        while (isRun)
    //        {
    //            lock (obj)
    //            {
    //                Console.SetCursorPosition(10, 5);
    //                Console.ForegroundColor = ConsoleColor.Yellow;
    //                Console.Write("●");
    //            }
    //            //Thread.Sleep(1000);
    //        }
    //    }
    //}

    class InputThread
    {
        public Thread inputthread;
        public event Action inputEvent;
        private static InputThread instance = new InputThread();
        public static InputThread Instance
        {
            get{ return instance;}
        }
        public InputThread()
        {
            Console.Write("调用构造函数");
            inputthread = new Thread(InputCheck);
            inputthread.IsBackground = true;
            //inputthread.Start();
        }
        public void InputCheck()
        {
            while (true)
            {
                if (inputEvent != null)
                    inputEvent();
            }
        }
    }
    enum NowDir
    {
        up,down, left, right
    }
    class Icon
    {
        public int x, y;
        public NowDir dir;
        public Icon(int x, int y, NowDir dir)
        {
            this.x = x;
            this.y = y;
            this.dir = dir;
        }   
        //移动
        public void Move()
        {
            switch (dir)
            {
                case NowDir.up:
                    y -= 1;
                    break;
                case NowDir.down:
                    y += 1;
                    break;
                case NowDir.left:
                    x -= 2;
                    break;
                case NowDir.right:
                    x += 2;
                    break;
            }
        }
        public void Draw()
        {
            Console.SetCursorPosition(x, y);
            Console.Write("■");
        }
        public void Clear()
        {
            Console.SetCursorPosition(x, y);
            Console.Write("  ");
        }
        public void Turn(NowDir dir)
        {
            this.dir = dir;
        }
    }
    class Program
    {
        static Icon icon;
        static void Main(string[] args)
        {
            Console.CursorVisible = false;
            icon = new Icon(10, 5, NowDir.right);
            icon.Draw();
            //InputThread.Instance.inputEvent += NewThread;
            InputThread t = new InputThread();
            t.inputEvent += NewThread;
            t.inputthread.Start();
            while (true)
            {
                Thread.Sleep(1000);
                icon.Clear();
                icon.Move();
                icon.Draw();
            }
        }
        static void NewThread()
        {
            while(true)
            {
                switch (Console.ReadKey(true).Key)
                {
                    case ConsoleKey.UpArrow:
                        icon.Turn(NowDir.up);
                        break;
                    case ConsoleKey.DownArrow:
                        icon.Turn(NowDir.down);
                        break;
                    case ConsoleKey.LeftArrow:
                        icon.Turn(NowDir.left);
                        break;
                    case ConsoleKey.RightArrow:
                        icon.Turn(NowDir.right);
                        break;
                }
            }
        }
    }
}