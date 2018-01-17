using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Vigenere.src;

namespace Vigenere
{
    class Program
    {
        static void Main(string[] args)
        {
            var cryptor = new  CryptVigenere();

            cryptor.Encrypt("LEMON", "ATTACKATDAWN");
            cryptor.Decrypt("LEMON", "LXFOPVEFRNHR");
        }
    }
}
