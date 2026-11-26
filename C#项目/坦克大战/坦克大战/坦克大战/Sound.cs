using System;
using System.Collections.Generic;
using System.Linq;
using System.Media;
using System.Text;
using System.Threading.Tasks;

namespace 坦克大战
{
    class Sound
    {
        public Sound() { }
        public static void PlayStart()
        {
            SoundPlayer sp = new SoundPlayer(SoundCollect.start); 
            sp.Play();
        }
        public static void PlayHit()
        {
            SoundPlayer sp = new SoundPlayer(SoundCollect.hit);
            sp.Play();
        }
        public static void PlayFire()
        {
            SoundPlayer sp = new SoundPlayer(SoundCollect.fire);
            sp.Play();
        }
        public static void PlayBlast()
        {
            SoundPlayer sp = new SoundPlayer(SoundCollect.blast);
            sp.Play();
        }
        public static void PlayAdd()
        {
            SoundPlayer sp = new SoundPlayer(SoundCollect.add);
            sp.Play();
        }
    }
}
