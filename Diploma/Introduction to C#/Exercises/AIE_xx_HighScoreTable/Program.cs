using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace AIE_xx_HighScoreTable
{
    class ScoreEntry
    {
        public string name;
        public int score;
        public ScoreEntry(string name, int score)
        {
            this.name = name;
            this.score = score;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            List<ScoreEntry> scores = new List<ScoreEntry>()
            {
                new ScoreEntry("bob", 12),
                new ScoreEntry("fred", 20),
                new ScoreEntry("ted", 6),
                new ScoreEntry("tom", 42),
                new ScoreEntry("harry", 9),
            };

            // save the scores
            SerialiseScores("highscores.txt", scores);

            // clear the scores
            scores = new List<ScoreEntry>();

            // read the scores
            DeSerialiseScoreos("highscores.txt", scores);

            // print scores
            foreach (var entry in scores)
            {
                Console.WriteLine($"{entry.name}:{entry.score}");               
            }
            Console.ReadKey();
        }
        static void SerialiseScores(string filename, List<ScoreEntry> scores)
        {
            FileInfo fileInfo = new FileInfo(filename);
            Directory.CreateDirectory(fileInfo.Directory.FullName);

            using(StreamWriter sw = File.CreateText(filename))
            {
                foreach(var entry in scores)
                {
                    sw.WriteLine($"{entry.name} {entry.score}");
                }
            }
        }
        static void DeSerialiseScoreos(string filename, List<ScoreEntry> scores)
        {
            using(StreamReader sr = File.OpenText(filename))
            {
                string line;
                while ((line = sr.ReadLine()) != null)
                {
                    var lineIntems = line.Split(' ');
                    string name = lineIntems[0];
                    int.TryParse(lineIntems[1], out int score);

                    var entry = new ScoreEntry(name, score);
                    scores.Add(entry);
                }
            }
        }
    }
}
