using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace 俄罗斯方块
{
    class Map : IDraw
    {
        //固定墙壁
        private List<DrawObject> walls = new List<DrawObject>();
        //动态墙壁
        public List<DrawObject> dynamicWalls = new List<DrawObject>();
        private int[] recordInfo;//记录一行有多少个方块
        private int w;//记录横向方块的个数

        private GameScene scene;
        public Map(GameScene scene)
        {
            this.scene = scene;
            //初始化削层数组
            recordInfo = new int[Game.h-6];
            for(int i=0;i<Game.w;i+=2)//添加横向墙壁
            {
                walls.Add(new DrawObject(E_DrawType.wall, i, Game.h - 6));
                w++;
            }
            for(int i=0;i<Game.h-6;i++)//添加纵向墙壁
            {
                walls.Add(new DrawObject(E_DrawType.wall, 0, i));
                walls.Add(new DrawObject(E_DrawType.wall, Game.w-2, i));
            }
        }
        public void Draw()
        {
            for (int i = 0; i < walls.Count; i++)
            {
                walls[i].Draw();
            }
            //绘制动态墙
            for(int i = 0; i < dynamicWalls.Count; i++)
            {
                dynamicWalls[i].Draw();
            }
        }
        //清除动态墙壁
        public void ClearDraw()
        {
            for(int i=0;i<dynamicWalls.Count;i++)
            {
                dynamicWalls[i].Clean();
            }
        }
        //在外部添加动态方块
        public void Addwalls(List<DrawObject> walls)
        {
            for(int i=0;i<walls.Count;i++)
            {
                walls[i].ChangeType(E_DrawType.wall);
                //结束
                if (walls[i].pos.y <= 0)
                {
                    //关闭线程
                    this.scene.StopThread();
                    //切换到结束界面
                    Game.ChangeScene(E_SceneType.End);
                    return;
                }
                dynamicWalls.Add(walls[i]);
                //计数
                recordInfo[Game.h - 6 - 1 - walls[i].pos.y]++;
            }
            //先擦除
            ClearDraw();
            //检测移除
            CheckClear();
            //重新画
            Draw();
        }

        //清理最后一层
        public void CheckClear()
        {
            List<DrawObject> temp = new List<DrawObject>();
            for(int i=0;i<recordInfo.Length;i++)
            {
                //小方块计数值==w-2
                if (recordInfo[i]==w-2)
                {
                    for(int j=0;j<dynamicWalls.Count;j++)
                    {
                        if(i==Game.h-6-1-dynamicWalls[j].pos.y)
                        {
                            //移除方块，先存入临时变量
                            temp.Add(dynamicWalls[j]);
                        }
                        //下移方块
                        else if (i< Game.h - 6 - 1 - dynamicWalls[j].pos.y)
                        {
                            dynamicWalls[j].pos.y++;
                        }
                    }
                    //移除这一行方块
                    for(int j=0;j<temp.Count;j++)
                    {
                        dynamicWalls.Remove(temp[j]);
                    }
                    //加分
                    GameScene.score += 10;
                    //更新数组内容
                    for (int j=i;j<recordInfo.Length-1;j++)
                    {
                        recordInfo[j]=recordInfo[j+1];
                    }
                    //置空最顶层
                    recordInfo[recordInfo.Length-1]=0;
                    //消层后，再从0行开始检测
                    CheckClear();
                    break;//递归返回
                }
            }
        }
    }
}
