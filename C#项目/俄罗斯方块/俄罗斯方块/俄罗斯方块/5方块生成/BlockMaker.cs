using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 俄罗斯方块
{
    //方块旋转方向
    enum E_ChangeType
    {
        left,
        right
    }
    class BlockMaker : IDraw //要绘制方块
    {
        //方块
        private List<DrawObject> blocks;
        //记录方块的类型，和坐标信息
        private Dictionary<E_DrawType,BlockInfo> blockInfo;
        //记录当前方块的具体信息，通过blockInfo得到
        private BlockInfo nowInfo;
        //当前是第几个形态
        private int index;
        public BlockMaker()//存储方块信息
        {
            blockInfo = new Dictionary<E_DrawType, BlockInfo>();
            blockInfo.Add(E_DrawType.cube, new BlockInfo(E_DrawType.cube));
            blockInfo.Add(E_DrawType.line, new BlockInfo(E_DrawType.line));
            blockInfo.Add(E_DrawType.tank, new BlockInfo(E_DrawType.tank));
            blockInfo.Add(E_DrawType.left_ladder, new BlockInfo(E_DrawType.left_ladder));
            blockInfo.Add(E_DrawType.right_ladder, new BlockInfo(E_DrawType.right_ladder));
            blockInfo.Add(E_DrawType.left_long_ladder, new BlockInfo(E_DrawType.left_long_ladder));
            blockInfo.Add(E_DrawType.right_long_ladder, new BlockInfo(E_DrawType.right_long_ladder));
            //调用随机方块
            RandomCreate();
        }
        //随机生成方块
        public void RandomCreate()
        {
            //随机方块类型
            Random r = new Random();
            E_DrawType type = (E_DrawType)r.Next(1, 8);//生成类型
            //每次生成大方块，就是生成4个小方块
            blocks = new List<DrawObject>()
            {
                new DrawObject(type),
                new DrawObject(type),
                new DrawObject(type),
                new DrawObject(type)
            };
            nowInfo = blockInfo[type];//通过键 查询到当前类型的方块坐标变化数组
            //原点
            blocks[0].pos = new Position(24, -5);
            //随机选取当前类型的方块的 某一种形态
            index = r.Next(0,nowInfo.Count);
            Position[] pos = nowInfo[index];//通过形态键 得到其他三个方块相对原点的坐标信息
            for (int i=0;i<pos.Length;i++)
            {
                blocks[i + 1].pos = blocks[0].pos + pos[i];
            }
        }
        public void Draw()
        {
            for (int i = 0; i < blocks.Count;i++)
            {
                blocks[i].Draw();
            }
        }
        public void CleanDraw()
        {
            for(int i=0;i<blocks.Count;i++)
            {
                blocks[i].Clean();
            }
        }
        //变形方法
        public void Change(E_ChangeType type)
        {
            //把先前的擦除
            CleanDraw();
            switch (type)
            {
                case E_ChangeType.left:
                    index--;
                    if(index<0)
                        index = nowInfo.Count-1;
                    break;
                case E_ChangeType.right:
                    index++;
                    if (index >= nowInfo.Count)
                        index = 0;
                    break;
            }
            //通过索引下标 得到其他方块的位置信息
            Position[] pos = nowInfo[index];
            for (int i = 0; i < pos.Length; i++)
            {
                blocks[i + 1].pos = blocks[0].pos + pos[i];
            }
            //改变后再画
            Draw();
        }
        //判断是否可以变形
        public bool ifChange(E_ChangeType type,Map map)
        {
            //用临时变量进行模拟变形，不改变原来的索引，方面恢复
            int nowindex = index;
            //模拟变形
            switch (type)
            {
                case E_ChangeType.left:
                    nowindex--;
                    if (nowindex < 0)
                        nowindex = nowInfo.Count - 1;
                    break;
                case E_ChangeType.right:
                    nowindex++;
                    if (nowindex >= nowInfo.Count)
                        nowindex = 0;
                    break;
            }
            Position[] nowpos = nowInfo[nowindex];//用模拟索引得到临时的坐标数组
            Position temp;
            //判断是否超出边界
            for(int i=0;i<nowpos.Length;i++)
            {
                temp = blocks[0].pos + nowpos[i];
                if (temp.x < 2 || temp.x >= Game.w - 2 || temp.y >= Game.h - 6)
                    return false;
            }
            //判断是否和动态方块重合
            for (int i = 0; i < nowpos.Length; i++)
            {
                temp = blocks[0].pos + nowpos[i];
                for(int j=0;j<map.dynamicWalls.Count;j++)
                {
                    if(temp == map.dynamicWalls[j].pos)
                        return false;
                }
            }
            return true;
        }

        //移动方法
        public void MoveBlock(E_ChangeType type)
        {
            //擦除
            CleanDraw();
            Position pos = new Position();
            if(type==E_ChangeType.left)
                pos = new Position(-2, 0);
            if(type==E_ChangeType.right)      
                pos = new Position(2, 0);
            //移动方块
            for(int i = 0;i<blocks.Count;i++)
            {
                blocks[i].pos += pos;
            }
            //重新画
            Draw();
        }
        //判断是否可以移动
        public bool ifMove(E_ChangeType type,Map map)
        {
            Position pos = new Position();
            if (type == E_ChangeType.left)
                pos = new Position(-2, 0);
            if (type == E_ChangeType.right)
                pos = new Position(2, 0);
            //模拟移动
            Position nowpos;
            for(int i=0;i<blocks.Count;i++)
            {
                nowpos = blocks[i].pos + pos;
                if(nowpos.x <2||nowpos.x>=Game.w-2)
                    return false;
            }
            for (int i = 0; i < blocks.Count; i++)
            {
                nowpos = blocks[i].pos + pos;
                for(int j=0;j< map.dynamicWalls.Count;j++)
                {
                    if(nowpos== map.dynamicWalls[j].pos) 
                        return false;
                }
            }
            return true;
        }

        //自动向下
        public void AutoMove()
        {
            //先擦
            CleanDraw();
            for(int i =0;i<blocks.Count;i++)
            {
                blocks[i].pos.y += 1;
            }
            //再画
            Draw();
        }
        //是否可以自动移动
        public bool canMove(Map map)
        {
            Position movepos = new Position(0,1);
            Position pos;
            for(int i=0;i<blocks.Count;i++)
            {
                pos = blocks[i].pos + movepos;
                if(pos.y>=Game.h-6)
                {
                    //把方块变成动态墙壁
                    map.Addwalls(blocks);
                    //生成新的方块
                    RandomCreate();
                    return false;
                }
            }
            for (int i = 0; i < blocks.Count; i++)
            {
                pos = blocks[i].pos + movepos;
                for(int j=0;j< map.dynamicWalls.Count;j++)
                {
                    if (pos == map.dynamicWalls[j].pos)
                    {
                        //把方块变成动态墙壁
                        map.Addwalls(blocks);
                        //生成新的方块
                        RandomCreate();
                        return false;
                    }
                }
            }
            return true;
        }
    }
}
