using System;
using System.Security.Cryptography;
namespace 飞行棋
{
    #region 场景选择
    enum E_sceneType
    {
        Begin,
        Game,
        End
    }
    #endregion

    #region 格子结构体和枚举
    enum E_GridType
    {
        Normal,
        Boom,
        Pause,
        Tp
    }
    struct Vector2 //位置结构体
    {
        public int x, y;
        public Vector2 (int x, int y)
        {
            this.x = x; this.y = y;
        }
    }
    struct Grid
    {
        public E_GridType type;
        public Vector2 pos;
        public Grid(E_GridType type,int x,int y)
        {
            this.type = type;
            pos = new Vector2(x,y);
        }
        public void Draw()
        {
            Console.SetCursorPosition(pos.x, pos.y);
            switch (type)
            {
                case E_GridType.Normal:
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.Write("□");
                    break;
                case E_GridType.Boom:
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.Write("●");
                    break;
                case E_GridType.Pause:
                    Console.ForegroundColor = ConsoleColor.Blue;
                    Console.Write("‖");
                    break;
                case E_GridType.Tp:
                    Console.ForegroundColor = ConsoleColor.Magenta;
                    Console.Write("∞");
                    break;
          
            }
        }
    }
    #endregion

    #region 地图结构体
    struct Map
    {
        public Grid[] g;
        public Map(int x,int y,int num) //给出地图的起点，格子的数量
        { 
            g = new Grid[num];
            Random r = new Random();
            int index = 0; 
            int flagX = 0;int flagY = 0;
            int step = 2;
            for (int i = 0; i < num; i++)
            {
                //随机生成每个格子
                index = r.Next(0,101);
                if(index<85 || i==0 || i==num-1)//普通格子 以及收尾两个格子的特殊情况
                {
                    g[i].type = E_GridType.Normal;
                }
                else if (index >=85&&index<90)//炸弹
                {
                    g[i].type = E_GridType.Boom;
                }
                else if (index >= 90 && index < 95)//暂停
                {
                    g[i].type = E_GridType.Pause;
                }
                else
                {
                    g[i].type = E_GridType.Tp;//传送
                }
                //记录每个格子的位置
                g[i].pos = new Vector2(x, y);
                //变化位置
                if(flagX == 10)
                {
                    y += 1;flagY++;
                    if(flagY==2)
                    {
                        flagX = 0;flagY = 0;
                        step = -step;
                    }
                }
                else
                {
                    x += step; flagX++;
                }
            }
        }
        public void Draw()
        {
            for(int i=0;i<g.Length;i++)
            {
                g[i].Draw(); 
            }
        }
    }
    #endregion

    #region 玩家枚举和玩家结构体
    enum E_PlayerType
    {
        Player,
        Robot
    }
    struct Player
    {
        public E_PlayerType type;
        public int nowIndex;//玩家在map中的位置
        public bool ifpause;//是否暂停
        public Player(E_PlayerType type, int nowIndex)
        {
            this.type = type;
            this.nowIndex = nowIndex;
            ifpause = false;
        }
        public void Draw(Map info)
        {
            Grid g = info.g[nowIndex];
            Console.SetCursorPosition(g.pos.x, g.pos.y);//设置光标
            switch (type)
            {
                case E_PlayerType.Player:
                    Console.ForegroundColor = ConsoleColor.DarkBlue;
                    Console.Write("★");
                    break;
                case E_PlayerType.Robot:
                    Console.ForegroundColor = ConsoleColor.Cyan;
                    Console.Write("¤");
                    break;
            }
        }
    }
    #endregion

    class Program
    {
        #region 控制台初始化
        static void ConsoleInit(int w,int h)
        {
            Console.CursorVisible = false;//隐藏光标
            Console.SetWindowSize(w,h);
            Console.SetBufferSize(w,h);
        }
        #endregion

        static void Main(string[] args)
        {
            #region 控制台
            int w = 50; int h = 30;
            ConsoleInit(w, h);
            #endregion

            #region 场景选择
            E_sceneType sceneselect = E_sceneType.Begin;
            bool isend = false;
            while (true)
            {
                switch (sceneselect)
                {
                    case E_sceneType.Begin:
                        Console.Clear();
                        BeginScene(w, h,ref sceneselect);//开始场景
                        break;
                    case E_sceneType.Game:
                        Console.Clear();
                        GameScene(w, h,ref sceneselect);//游戏场景
                        break;
                    case E_sceneType.End:
                        Console.Clear();
                        isend = EndScene(w, h);
                        break;
                    default:
                        break;
                }
                if (isend) break;
            }
            #endregion
        }

        #region 开始场景
        static void BeginScene(int w,int h, ref E_sceneType sceneselect)
        {
            Console.SetCursorPosition(w / 2 - 3, 8);
            Console.Write("飞行棋");
            int input = 0;//选择开始或者退出
            bool isQuit = false;//判断是否退出这个函数
            while (true)
            {
                Console.SetCursorPosition(w / 2 - 4, 13);
                Console.ForegroundColor = input == 0 ? ConsoleColor.Red : ConsoleColor.White;//是0则选择开始游戏为红色
                Console.Write("开始游戏");
                Console.SetCursorPosition(w / 2 - 4, 15);
                Console.ForegroundColor = input == 1 ? ConsoleColor.Blue : ConsoleColor.White; //是1则选择退出游戏为蓝色
                Console.Write("退出游戏");
                //平时.KeyChar可以获得一个字符，通过字符转换数字来判断是什么按键。而ReadKey.Key可以返回枚举
                switch(Console.ReadKey(true).Key)
                {
                    case ConsoleKey.W://0为开始
                        input--;
                        if (input < 0) input = 0;
                        break;
                    case ConsoleKey.S://1为退出
                        input++;
                        if (input > 1) input = 1;
                        break;
                    case ConsoleKey.J://按J则进入游戏
                        if(input == 0)
                        {
                            //进入
                            sceneselect = E_sceneType.Game;
                            //退出这个函数
                            isQuit = true;
                        }
                        else
                        {
                            //退出
                            Environment.Exit(0);
                        }
                        break;
                    default:
                        break;
                }
                if(isQuit)
                {
                    break;
                }
            }
        }
        #endregion

        #region 通用元素
        static void DrawWall(int w, int h)
        {
            Console.ForegroundColor = ConsoleColor.Yellow;
            //画墙
            for (int i = 0;i < w; i+=2)
            {
                Console.SetCursorPosition(i, 0);//设置光标位置 最上方的墙
                Console.Write("≡");
                Console.SetCursorPosition(i, h - 6); //设置光标位置 中间的墙
                Console.Write("≡");
                Console.SetCursorPosition(i, h - 11);
                Console.Write("≡");
                Console.SetCursorPosition(i, h-1);//设置光标位置 最下方的墙
                Console.Write("≡");
            }
            for(int i = 0;i<h;i++)
            {
                Console.SetCursorPosition(0, i);
                Console.Write("≡");
                Console.SetCursorPosition(w-2, i); 
                Console.Write("≡");
            }
            //文字信息
            Console.ForegroundColor = ConsoleColor.White;
            Console.SetCursorPosition(2, h - 10);
            Console.Write("□:普通格子");
            Console.ForegroundColor = ConsoleColor.Blue;
            Console.SetCursorPosition(2, h - 9);
            Console.Write("‖:暂停,停止一回合不动");
            Console.ForegroundColor = ConsoleColor.Red;
            Console.SetCursorPosition(26, h - 9);
            Console.Write("●:炸弹,倒退5格");
            Console.ForegroundColor = ConsoleColor.Magenta;
            Console.SetCursorPosition(2, h - 8);
            Console.Write("∞:传送，随机移位"); 
            Console.ForegroundColor = ConsoleColor.DarkBlue;
            Console.SetCursorPosition(2, h - 7);
            Console.Write("★:玩家");
            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.SetCursorPosition(12, h - 7);
            Console.Write("¤:电脑");
            Console.ForegroundColor = ConsoleColor.Green;
            Console.SetCursorPosition(22, h - 7);
            Console.Write("※:二者重合");
            Console.ForegroundColor = ConsoleColor.White;
            Console.SetCursorPosition(2, h - 5);
            Console.Write("按任意键开始扔骰子...");
        }
        #endregion

        #region 绘制玩家
        static void DrawPlayer(Player player,Player robot,Map map)
        {
            //重合时
            if(player.nowIndex == robot.nowIndex)
            {
                Grid grid = map.g[player.nowIndex];
                Console.SetCursorPosition(grid.pos.x, grid.pos.y);
                Console.ForegroundColor = ConsoleColor.Green;
                Console.Write("※");
            }
            else
            {
                player.Draw(map);robot.Draw(map);
            }
        }
        #endregion

        #region 擦除函数
        static void ClearInfo(int w, int h)
        {
            Console.SetCursorPosition(2, h - 5);
            Console.Write("                             ");
            Console.SetCursorPosition(2, h - 4);
            Console.Write("                             ");
            Console.SetCursorPosition(2, h - 3);
            Console.Write("                             ");
            Console.SetCursorPosition(2, h - 2);
            Console.Write("                             ");
        }
        #endregion

        #region 扔骰子
        static bool RemovePlayer(int w,int h,ref Player p,ref Player p2,Map map )
        {
            //擦除信息
            ClearInfo(w,h);
            Console.ForegroundColor = p.type == E_PlayerType.Player ? ConsoleColor.DarkBlue : ConsoleColor.Cyan;
            //扔之前 判断是否处于暂停状态
            if (p.ifpause == true)
            {
                Console.SetCursorPosition(2, h - 5);
                Console.Write("{0}被暂停,停止一回合",p.type==E_PlayerType.Player?"玩家":"电脑");
                p.ifpause = false;
                return false;
            }
            //随机扔1-6，改变nowIndex
            Random r = new Random();
            int rnum = r.Next(1, 7);
            p.nowIndex += rnum;
            //打印点数
            Console.SetCursorPosition(2, h - 5);
            Console.Write("{0}扔出了{1}点", p.type == E_PlayerType.Player ? "玩家" : "电脑",rnum);
            //到终点
            if ( p.nowIndex >= map.g.Length-1 )
            {
                p.nowIndex = map.g.Length - 1;
                Console.SetCursorPosition(2, h - 4);
                Console.Write("{0}获胜", p.type == E_PlayerType.Player ? "玩家" : "电脑");
                Console.SetCursorPosition(2, h - 3);
                Console.Write("请按任意键结束游戏...");
                return true;
            }
            else
            {
                //判断格子种类
                Grid grid = map.g[p.nowIndex];
                switch (grid.type)
                {
                    case E_GridType.Normal:
                        Console.SetCursorPosition(2, h - 4);
                        Console.Write("{0}正常行走", p.type == E_PlayerType.Player ? "玩家" : "电脑");
                        Console.SetCursorPosition(2, h - 3);
                        Console.Write("请按任意键，让{0}开始投骰子", p.type == E_PlayerType.Player ? "电脑" : "玩家");
                        //普通格子不用处理
                        break;
                    case E_GridType.Boom:
                        //炸弹倒退5格
                        Console.SetCursorPosition(2, h - 4);
                        Console.Write("{0}踩到炸弹,后退5格", p.type == E_PlayerType.Player ? "玩家" : "电脑");
                        Console.SetCursorPosition(2, h - 3);
                        Console.Write("请按任意键，让{0}开始投骰子", p.type == E_PlayerType.Player ? "电脑" : "玩家");
                        p.nowIndex -= 5;
                        if (p.nowIndex < 0)
                            p.nowIndex = 0;
                        break;
                    case E_GridType.Pause:
                        Console.SetCursorPosition(2, h - 4);
                        Console.Write("这一回合{0}被暂停了", p.type == E_PlayerType.Player ? "玩家" : "电脑");
                        Console.SetCursorPosition(2, h - 3);
                        Console.Write("请按任意键，让{0}开始投骰子", p.type == E_PlayerType.Player ? "电脑" : "玩家");
                        p.ifpause = true;
                        break;
                    case E_GridType.Tp:
                        Console.SetCursorPosition(2, h - 4);
                        Console.Write("{0}来到传送点", p.type == E_PlayerType.Player ? "玩家" : "电脑");
                        rnum = r.Next(1, 91);
                        if(rnum <= 30)
                        {
                            Console.SetCursorPosition(2, h - 3);
                            Console.Write("{0}退后5格", p.type == E_PlayerType.Player ? "玩家" : "电脑");
                            p.nowIndex -= 5;
                            if (p.nowIndex < 0)
                                p.nowIndex = 0;
                        }
                        else if(rnum <= 60)
                        {
                            Console.SetCursorPosition(2, h - 3);
                            Console.Write("{0}下一回合被暂停行动", p.type == E_PlayerType.Player ? "玩家" : "电脑");
                            p.ifpause = true;
                        }
                        else
                        {
                            Console.SetCursorPosition(2, h - 3);
                            Console.Write("{0}与{1}交换位置", p.type,p2.type);
                            int temp = p.nowIndex;
                            p.nowIndex = p2.nowIndex;
                            p2.nowIndex = temp; 
                        }
                        Console.SetCursorPosition(2, h - 2);
                        Console.Write("请按任意键，让{0}开始投骰子", p.type == E_PlayerType.Player ? "电脑" : "玩家");
                        break;
                }
            }
            return false;
        }
        #endregion

        #region 游戏场景
        static void GameScene(int w,int h, ref E_sceneType sceneselect)
        {
            //绘制通用
            DrawWall(w, h);
            //绘制地图
            Map map = new Map(14,3,81);
            map.Draw();
            //绘制玩家
            Player player = new Player(E_PlayerType.Player,0);
            Player robot = new Player(E_PlayerType.Robot, 0);
            DrawPlayer(player, robot, map);
            //游戏逻辑
            bool ifend = false;//是否结束游戏
            while (true)
            {
                //真人部分
                //检查按键
                Console.ReadKey(true);
                //扔骰子移动角色
                ifend = RemovePlayer(w, h, ref player, ref robot, map);
                //更新地图
                map.Draw();
                //更新玩家
                DrawPlayer(player, robot, map);
                //判断是否结束
                if (ifend)
                {
                    Console.ReadKey(true);
                    //改变场景
                    sceneselect = E_sceneType.End;
                    break;
                }
                //电脑部分
                //检查按键
                Console.ReadKey(true);
                //扔骰子移动角色
                ifend = RemovePlayer(w, h, ref robot, ref player, map);
                //更新地图
                map.Draw();
                //更新玩家
                DrawPlayer(player, robot, map);
                //判断是否结束
                if (ifend)
                {
                    Console.ReadKey(true);
                    //改变场景
                    sceneselect = E_sceneType.End;
                    break;
                }
            }
        }
        #endregion

        #region 结束场景
        static bool EndScene(int w,int h)
        {
            Console.SetCursorPosition(w / 2 - 3, 8);
            Console.ForegroundColor = ConsoleColor.Red;
            Console.Write("游戏结束");
            return true;
        }
        #endregion
    }
}