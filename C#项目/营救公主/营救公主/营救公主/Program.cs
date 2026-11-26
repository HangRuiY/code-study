using System;
using System.Globalization;

namespace 营救公主
{
    #region 场景选择的枚举
    enum E_sceneType
    {
        Begin,
        Game,
        End
    }
    #endregion

    #region 人物枚举
    enum E_PlayerType
    {
        Human,
        Boss
    }
    #endregion

    #region 人物结构体
    struct Player
    {
        public int Player_x;
        public int Player_y;
        public int Player_AtkMin;
        public int Player_AtkMax;
        public int Player_hp;
        public E_PlayerType Player_type;
        public Player(int Player_x, int Player_y, int Player_AtkMin, int Player_AtkMax, int Player_hp, E_PlayerType PlayerType)
        {
            this.Player_x = Player_x;
            this.Player_y = Player_y;
            this.Player_AtkMin = Player_AtkMin;
            this.Player_AtkMax = Player_AtkMax;    
            this.Player_hp = Player_hp;
            this.Player_type = PlayerType;
        }
        public void Draw()
        {
            Console.SetCursorPosition(Player_x,Player_y);
            if(Player_type == E_PlayerType.Human)
            {
                Console.ForegroundColor = ConsoleColor.Blue;
                Console.Write("◆");
            }
            else
            {
                Console.ForegroundColor = ConsoleColor.Red;
                Console.Write("●");
            }
        }
    }
    #endregion
    class Program
    {
        #region 控制台
        static void ConsoleInit(int w, int h)
        {
            Console.CursorVisible = false;//隐藏光标
            Console.SetWindowSize(w, h);
        }
        #endregion

        #region 开始场景
        static void BeginScene(int w,int h, ref E_sceneType sceneselect)
        {
            Console.SetCursorPosition(w / 2 - 4, 8);
            Console.Write("营救公主");
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
                switch (Console.ReadKey(true).Key)
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
                        if (input == 0)
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
                if (isQuit)
                {
                    break;
                }
            }
        }
        #endregion

        #region 游戏场景
        static void GameScene(int w,int h,ref E_sceneType sceneselect)
        {
            //画墙
            DrawWall(w,h);
            //生成boss
            Random r = new Random();
            int bx = r.Next(20, 31);
            if (bx % 2 != 0) bx++;
            int by = r.Next(12,18);
            Player boss = new Player(bx,by,10,15,100,E_PlayerType.Boss);
            boss.Draw();
            //生成人物
            int px = r.Next(2, 48);
            if(px % 2 != 0) px++;
            int py = r.Next(1,10);
            Player player = new Player(px, py, 12, 14, 100, E_PlayerType.Human);
            player.Draw();
            //游戏逻辑
            bool ifend = false;//是否结束游戏
            while (true)
            {
                if (ifend)
                {
                    sceneselect = E_sceneType.End;
                    break;
                }
                //玩家移动
                switch (Console.ReadKey(true).Key)
                {
                    case ConsoleKey.W:
                        if (player.Player_y - 1 == boss.Player_y && player.Player_x == boss.Player_x)
                        {
                            Battle(w,h,ref player,ref boss,ref ifend);
                            break;
                        }
                        Console.SetCursorPosition(player.Player_x,player.Player_y);
                        Console.Write("  ");
                        player.Player_y -= 1;
                        if(player.Player_y <= 1)
                        {
                            player.Player_y = 1;
                        }
                        player.Draw();
                        break;
                    case ConsoleKey.A:
                        if (player.Player_y == boss.Player_y && player.Player_x - 2 == boss.Player_x)
                        {
                            Battle(w,h,ref player, ref boss , ref ifend);
                            break;
                        }
                        Console.SetCursorPosition(player.Player_x, player.Player_y);
                        Console.Write("  ");
                        player.Player_x -= 2;
                        if (player.Player_x <= 2)
                        {
                            player.Player_x = 2;
                        }
                        player.Draw();
                        break;
                    case ConsoleKey.S:
                        if (player.Player_y + 1== boss.Player_y && player.Player_x== boss.Player_x)
                        {
                            Battle(w,h,ref player, ref boss, ref ifend); 
                            break;
                        }
                        Console.SetCursorPosition(player.Player_x, player.Player_y);
                        Console.Write("  ");
                        player.Player_y += 1;
                        if (player.Player_y >= h-10)
                        {
                            player.Player_y = h-10;
                        }
                        player.Draw();
                        break;
                    case ConsoleKey.D:
                        if (player.Player_y == boss.Player_y && player.Player_x + 2 == boss.Player_x)
                        {
                            Battle(w,h,ref player, ref boss , ref ifend);
                            break;
                        }
                        Console.SetCursorPosition(player.Player_x, player.Player_y);
                        Console.Write("  ");
                        player.Player_x += 2;
                        if (player.Player_x >= w-4)
                        {
                            player.Player_x = w-4;
                        }
                        player.Draw();
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
            for (int i = 0; i < w; i += 2)
            {
                Console.SetCursorPosition(i, 0);//设置光标位置 最上方的墙
                Console.Write("≡");
                Console.SetCursorPosition(i, h - 9);
                Console.Write("≡");
                Console.SetCursorPosition(i, h - 1);//设置光标位置 最下方的墙
                Console.Write("≡");
            }
            for (int i = 0; i < h; i++)
            {
                Console.SetCursorPosition(0, i);
                Console.Write("≡");
                Console.SetCursorPosition(w - 2, i);
                Console.Write("≡");
            }
        }
        #endregion

        #region 战斗环境
        static void Battle (int w,int h,ref Player player,ref Player boss, ref bool ifend)
        {
            Console.ForegroundColor = ConsoleColor.White;
            Random r = new Random();
            ifend = false;
            while (true)
            {
                if (boss.Player_hp <= 0)
                {
                    Console.SetCursorPosition(2, h - 5);
                    Console.Write("勇者战胜了怪物，救出了公主");
                    ifend = true;
                    break;
                }
                if (player.Player_hp <= 0)
                {
                    Console.SetCursorPosition(2, h - 4);
                    Console.Write("勇者输给了怪物，不能救公主了");
                    ifend = true;
                    break;
                }
                char c = Console.ReadKey(true).KeyChar;
                switch (c)
                {
                    case 'J':
                    case 'j':
                        int select1 = r.Next(0, 2);
                        int select2 = r.Next(0, 2);
                        if (select1 == 0 && select2 == 0)
                        {
                            boss.Player_hp -= player.Player_AtkMin;
                            Console.SetCursorPosition(2, h - 7);
                            Console.Write("勇者对怪物造成了{0}点伤害，怪物还剩下{1}点HP", player.Player_AtkMin, boss.Player_hp);
                            player.Player_hp -= boss.Player_AtkMin;
                            Console.SetCursorPosition(2, h - 6);
                            Console.Write("怪物对勇者造成了{0}点伤害，勇者还剩下{1}点HP", boss.Player_AtkMin, player.Player_hp);
                        }
                        else if (select1 == 0 && select2 == 1)
                        {
                            boss.Player_hp -= player.Player_AtkMin;
                            Console.SetCursorPosition(2, h - 7);
                            Console.Write("勇者对怪物造成了{0}点伤害，怪物还剩下{1}点HP", player.Player_AtkMin, boss.Player_hp);
                            player.Player_hp -= boss.Player_AtkMax;
                            Console.SetCursorPosition(2, h - 6);
                            Console.Write("怪物对勇者造成了{0}点伤害，勇者还剩下{1}点HP", boss.Player_AtkMax, player.Player_hp);
                        }
                        else if (select1 == 1 && select2 == 0)
                        {
                            boss.Player_hp -= player.Player_AtkMax;
                            Console.SetCursorPosition(2, h - 7);
                            Console.Write("勇者对怪物造成了{0}点伤害，怪物还剩下{1}点HP", player.Player_AtkMax, boss.Player_hp);
                            player.Player_hp -= boss.Player_AtkMin;
                            Console.SetCursorPosition(2, h - 6);
                            Console.Write("怪物对勇者造成了{0}点伤害，勇者还剩下{1}点HP", boss.Player_AtkMin, player.Player_hp);
                        }
                        else if (select1 == 1 && select2 == 1)
                        {
                            boss.Player_hp -= player.Player_AtkMax;
                            Console.SetCursorPosition(2, h - 7);
                            Console.Write("勇者对怪物造成了{0}点伤害，怪物还剩下{1}点HP", player.Player_AtkMax, boss.Player_hp);
                            player.Player_hp -= boss.Player_AtkMax;
                            Console.SetCursorPosition(2, h - 6);
                            Console.Write("怪物对勇者造成了{0}点伤害，勇者还剩下{1}点HP", boss.Player_AtkMax, player.Player_hp);
                        }
                        break;
                }
            }
        }

        #endregion
        static void Main(string[] args)
        {
            #region 控制台
            int w = 50; int h = 30;
            ConsoleInit(w, h);
            #endregion

            #region 选择场景
            E_sceneType sceneselect = E_sceneType.Begin;
            bool isend = false;
            while (true)
            {
                switch (sceneselect)
                {
                    case E_sceneType.Begin:
                        Console.Clear();
                        BeginScene(w,h, ref sceneselect);//开始场景
                        break;
                    case E_sceneType.Game:
                        Console.Clear();
                        GameScene(w, h,ref sceneselect);//游戏场景
                        break;
                    case E_sceneType.End:
                        Environment.Exit(0);
                        Console.Clear();
                        break;
                    default:
                        break;
                }
                if (isend) break;
            }
            #endregion
        }
    }
}