using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace TextAdventure
{
    /// <summary>
    /// A helper class for parsing verbs (commands) and capturing text arguments (names, places, etc...)
    /// You can easily add your own new verbs and they will automatically be registered
    ///
    /// These use regular expressions, see here: https://docs.microsoft.com/en-us/dotnet/standard/base-types/regular-expression-language-quick-reference
    /// </summary>
    internal class Verb
    {
        public static List<Verb> Verbs { get; private set; } = new List<Verb>();
        /// <summary>
        /// The look verb, for looking at things, supports "look" and "look at/in {target}" style syntax
        /// </summary>
        public static Verb Look = new Verb("look", @"look (?:(?:at|in|at the) )?(?<target>\w+)", @"look");
        public static Verb Go = new Verb("go", @"(?:go|walk) (?<target>[\w\-]+)");
        public static Verb PickUp = new Verb("pickup", @"(?:pick up|grab|get|take)(?: (?<target>\w+))?");
        public static Verb Eat = new Verb("eat", @"(?:eat|consume|bite|chew) (?<target>\w+)");
        public static Verb Put = new Verb("put", @"(?:put|place|shove) (?<target>\w+) (?:in|on|inside|on top of) (?<target2>\w+)");
        public static Verb Drop = new Verb("drop", @"(?:drop) (?<target>\w+)");
        public static Verb Quit = new Verb("quit", @"quit");
        public string Name { get; private set; }
        public List<Regex> Regex { get; private set; } = new List<Regex>();
        public static void RegisterVerb(Verb verb)
        {
            Verbs.Add(verb);
        }
        public Verb(string name, params string[] expressions)
        {
            Name = name;
            foreach (string expression in expressions)
            {
                Regex.Add(new Regex($"^{expression}$"));
            }
            RegisterVerb(this);
        }
    }
    /// <summary>
    /// A helper class designed to process text from the user into a more convenient format
    /// Verbs are automatically extracted and words are split up for ease of processing
    /// </summary>
    internal class UserInput
    {
        /// <summary>
        /// The original unaltered input string from the user
        /// </summary>
        public string Input { get; private set; }
        /// <summary>
        /// A detected verb (i.e. command) for the input string
        /// </summary>
        public Verb Verb { get; private set; }
        public string Target
        {
            get
            {
                if (Verb != null && Words.ContainsKey("target"))
                {
                    return Words["target"].Value;
                }
                return String.Empty;
            }
        }
        public string Target2
        {
            get
            {
                if (Verb != null && Words.ContainsKey("target2"))
                {
                    return Words["target2"].Value;
                }
                return String.Empty;
            }
        }
        public GroupCollection Words { get; private set; }
        /// <summary>
        /// Basic constructor, takes a string and processes it automatically
        /// </summary>
        /// <param name="input"></param>
        public UserInput(string input)
        {
            // Keep original raw input for custom commands
            Input = input;
            // Make string lowercase to simplify text processing
            string temp = input.ToLower();
            // Trim any whitespace
            temp.Trim();
            foreach (Verb verb in Verb.Verbs)
            {
                foreach (Regex regex in verb.Regex)
                {
                    var match = regex.Match(temp);
                    if (match.Success)
                    {
                        Words = match.Groups;
                        Verb = verb;
                        break;
                    }
                }
                if (Verb != null) break;
            }
        }
    }
}
