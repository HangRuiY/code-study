using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 坦克大战
{
    enum GameState
    {
        start,
        end
    }

    class GameFrameWork
    {
        public static Object obj;
        public static Graphics g;
        public static GameState state = GameState.start;
        public static void Start()
        {
            GameobjectMgr.CreatMap();
            GameobjectMgr.CreatMytank();
            GameobjectMgr.CreatPosistion();
            Sound.PlayStart();
        }
        public static void Update()
        {
            if(state == GameState.start)
            {
                GameobjectMgr.UpdateMap();
            }
            else if(state == GameState.end)
            {
                Gameover();
            }
        }
        public static void Gameover()
        {
            Bitmap i = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\GameOver.jpg");
            i.MakeTransparent(Color.Black);
            int x = 450/2-i.Width/2;
            int y = 450/2-i.Height/2;
            g.DrawImage(i, x, y);
        }
        public static void ChangeState()
        {
            state = GameState.end;
        }
    }
}
