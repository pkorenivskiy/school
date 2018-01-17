using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Vigenere.src
{
    class CryptVigenere
    {
        //private readonly char[] _symbols;
        private static readonly Dictionary<char, int> _symbols = new Dictionary<char, int>();

        static CryptVigenere()
        {
            var symbols = new List<char>();
            //for (char ch = 'a'; ch < 'z'; symbols.Add(ch++)) ;
            for (char ch = 'A'; ch < 'Z'; symbols.Add(ch++)) ;
            //symbols.Add('.');

            var i = 0;
            foreach (var ch in symbols)
                _symbols.Add(ch, i++);
        }

        public string Encrypt(string key, string text)
        {
            StringBuilder result = new StringBuilder();

            string toCrypt = normalyze(text);

            var i = 0;
            foreach(var ch in toCrypt)
            {
                var keyCh = key[i - (i / key.Length) * key.Length];

                var rowIndexKey = _symbols[keyCh];
                var rowIndexTxt = _symbols[ch];

                var indexOut = _symbols.Count < rowIndexKey + rowIndexTxt ? rowIndexKey + rowIndexTxt - _symbols.Count - 1 : rowIndexKey + rowIndexTxt;

                result.Append(_symbols.Where(x => x.Value == indexOut).FirstOrDefault().Key);

                Console.Write(keyCh);
                i++;
            }

            Console.WriteLine("LXFOPVEFRNHR");

            return result.ToString();
        }

        public string Decrypt(string key, string text)
        {
            StringBuilder result = new StringBuilder();

            string toDecrypt = normalyze(text);

            var i = 0;
            foreach(var ch in toDecrypt)
            {
                var keyCh = key[i - (i / key.Length) * key.Length];

                var rowIndexKey = _symbols[keyCh];
                var rowIndexTxt = _symbols[ch];

                var indexOut = _symbols.Count < rowIndexKey + rowIndexTxt ? rowIndexKey + rowIndexTxt - _symbols.Count - 1 : rowIndexKey + rowIndexTxt;

                result.Append(_symbols.Where(x => x.Value == indexOut).FirstOrDefault().Key);

                Console.Write(keyCh);

                i++;
            }


            return result.ToString();
        }

        private string normalyze(string text)
        {
            var result = text;
            foreach(var ch in text)
            {
                if (_symbols.ContainsKey(ch) == false)
                    result = result.Replace($"{ch}", string.Empty);
            }
            return result;
        }
    }
}
