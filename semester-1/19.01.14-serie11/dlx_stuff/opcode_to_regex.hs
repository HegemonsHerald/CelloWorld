import System.IO
import Data.Char

-- Takes a file called opcodes.txt, which is presumed to contain one opcode per line,
-- and produces another file from it, called opcodes_regex.txt, which contains a regex
-- pattern on each line, that would match any upper or lower casing of that opcode.

main = do
  opcodes <- readFile "opcodes.txt"
  writeFile "opcodes_regex.txt" $ transform opcodes

transform :: String -> String
transform = unlines . map toRegex . lines

toRegex :: String -> String
toRegex = foldr (\c acc -> '[' : toUpper c : toLower c : ']' : acc) ""
