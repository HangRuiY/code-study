using System;
using System.Collections.Generic;
using System.Text;
using 俄罗斯方块;

namespace 俄罗斯方块
{
    class GameScene : ISceneUpdate
    {
        Map map;
        BlockMaker blockMaker;
        public GameScene()
        {
            map = new Map(this);
            blockMaker = new BlockMaker();
            //添加事件 启动线程
            InputThread.Instance.inputEvent += CheckInputThread;
        }
        //输入线程
        private void CheckInputThread()
        {
            if (Console.KeyAvailable)//检测有输入 执行下面的代码
            {
                //在输入后面加锁，防止影响主线程
                lock (blockMaker)//下面代码执行完才能让其他线程用blockMaker
                {
                    switch (Console.ReadKey(true).Key)
                    {
                        case ConsoleKey.LeftArrow:
                            if (blockMaker.ifChange(E_ChangeType.left, map))
                                blockMaker.Change(E_ChangeType.left);
                            break;
                        case ConsoleKey.RightArrow:
                            if (blockMaker.ifChange(E_ChangeType.right, map))
                                blockMaker.Change(E_ChangeType.right);
                            break;
                        case ConsoleKey.A:
                            if (blockMaker.ifMove(E_ChangeType.left, map))
                                blockMaker.MoveBlock(E_ChangeType.left);
                            break;
                        case ConsoleKey.D:
                            if (blockMaker.ifMove(E_ChangeType.right, map))
                                blockMaker.MoveBlock(E_ChangeType.right);
                            break;
                        case ConsoleKey.S:
                            if (blockMaker.canMove(map))
                                blockMaker.AutoMove();
                            break;
                    }
                }
            }
        }
        //关闭线程
        public void StopThread()
        {
            //移出事件
            InputThread.Instance.inputEvent-=CheckInputThread;
        }
        public static int score = 0;
        public void Score()
        {
            Console.SetCursorPosition(4, Game.h - 3);
            Console.ForegroundColor = ConsoleColor.Red;
            Console.Write("得分:{0}",score.ToString());
        }
        public void Update()
        {
            lock ((blockMaker))//保持锁的对象相同
            {
                //地图绘制
                map.Draw();
                //分数栏目绘制
                Score();
                //方块绘制
                blockMaker.Draw();
                //方块自动移动
                if (blockMaker.canMove(map))
                    blockMaker.AutoMove();
            }
            //用线程休眠的形式延迟
            Thread.Sleep(400);
        }
    }
}
