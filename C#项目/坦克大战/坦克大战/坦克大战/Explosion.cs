using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 坦克大战
{
    class Explosion : GameObject
    {
        public bool needDestroy { get; set; }
        private int playspeed = 1;
        private int playcount = 0;
        private int index = 0;
        private Bitmap[] bmparrays = new Bitmap[] { 
            ImgCollect.Exp1,
            ImgCollect.Exp2,
            ImgCollect.Exp3,
            ImgCollect.Exp4,
            ImgCollect.Exp5
        };
        public Explosion(int x,int y)
        {
            foreach(Bitmap b in bmparrays)
            {
                b.MakeTransparent(Color.Black);
            }
            this.X = x - bmparrays[0].Width / 2;
            this.Y = y - bmparrays[0].Height / 2;
            this.needDestroy = false;
        }
        public override Image GetImage()
        {
            if (index > 4) return bmparrays[4];
            else return bmparrays[index];
        }
        public override void Draw()
        {
            playcount++;
            index = (playcount - 1) / playspeed;
            if(index >4)
            {
                needDestroy = true;
            }
            base.Draw();
        }
    }
}
