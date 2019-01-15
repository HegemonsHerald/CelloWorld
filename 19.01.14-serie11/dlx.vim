" Regexes for the various syntax elements

" Syntax groups based on regex
syntax match dlxComment  '/.*$'
syntax match dlxRegister '[rR][0-9]\{2}'
syntax match dlxLiteral  '#[0-9]*'
syntax match dlxDisplace '[0-9]\{4}([rR][0-9]\{2})'
syntax match dlxLabel	 '\<[a-zA-Z]\+\>:\='

" in:
"   for (expr1) while (expr2)
" match expr1
"
" \(for (\)\@<=		match right after 'for ('
" \() while (\)\@=	match ') while (' zero-width
"
" The \@= is used to specify, that a 'while' has to
" follow the expr1 part.
"
" Unlike \= \@= has to match, the match just doesn't
" affect the captured chars.
syntax match dlxX '\(for (\)\@<=\w\+\() while (\)\@='
highlight link dlxX SpellBad

" Syntax groups for Opcodes
syntax case ignore
syntax match dlxOpcode 'ADD'
syntax match dlxOpcode 'ADDI'
syntax match dlxOpcode 'ANDI'
syntax match dlxOpcode 'AND'
syntax match dlxOpcode 'ORI'
syntax match dlxOpcode 'OR'
syntax match dlxOpcode 'SEQI'
syntax match dlxOpcode 'SEQ'
syntax match dlxOpcode 'SLEI'
syntax match dlxOpcode 'SLE'
syntax match dlxOpcode 'SLLI'
syntax match dlxOpcode 'SLL'
syntax match dlxOpcode 'SLTI'
syntax match dlxOpcode 'SLT'
syntax match dlxOpcode 'SNEI'
syntax match dlxOpcode 'SNE'
syntax match dlxOpcode 'SRAI'
syntax match dlxOpcode 'SRA'
syntax match dlxOpcode 'SRLI'
syntax match dlxOpcode 'SRL'
syntax match dlxOpcode 'SUBI'
syntax match dlxOpcode 'SUB'
syntax match dlxOpcode 'XORI'
syntax match dlxOpcode 'XOR'
syntax match dlxOpcode 'BEQZ'
syntax match dlxOpcode 'BNEZ'
syntax match dlxOpcode 'J'
syntax match dlxOpcode 'JAL'
syntax match dlxOpcode 'JALR'
syntax match dlxOpcode 'JR'
syntax match dlxOpcode 'LW'
syntax match dlxOpcode 'SW'
syntax match dlxOpcode 'HALT'
syntax match dlxOpcode 'TRAP'
syntax match dlxOpcode 'MULT'
syntax case match

" Linking groups to hi-groups
" highlight link dlxComment	Comment
" highlight link dlxLiteral	Function
" highlight link dlxDisplace	Number
" highlight link dlxOpcode	Statement
" highlight dlxRegister	ctermfg=208 guifg=#fd971f
" highlight link dlxLabel Identifier

" Highlighting with colors that come closest to Hűser's Dark Theme
highlight dlxLabel	ctermfg=39
highlight dlxOpcode	ctermfg=197
highlight dlxRegister	ctermfg=214
highlight dlxLiteral	ctermfg=154
highlight dlxDisplace	ctermfg=217
