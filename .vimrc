syntax on

:set noswapfile
:set tabstop=4
:set autoindent
:set number relativenumber
:set mouse=a
inoremap [ []<left>
inoremap { {}<left>
inoremap {<CR> {<CR>}<ESC>O
inoremap {;<CR> {<CR>};<ESC>O

nmap <c-y> gg"+yG

command! Template -1read $HOME/vimfile/.snippets/cpp.snippets
command! Ft -1read $HOME/vimfile/.snippets/ft.cpp
command! St -1read $HOME/vimfile/.snippets/st.cpp
