function! MakeC()
    new | 0read !make -C './build/'
endfunction

silent command! Make call MakeC()

au BufWritePost * silent! CMake
au BufWritePost *.c,*.cpp,*.h silent! !ctags -R &

" Ctags mappings
" Opens tag in new tab
map <C-d> :tab split<CR>:exec("tag ".expand("<cword>"))<CR>
" Opens tag in vertical pane
" map <C-\> :vsp <CR>:exec("tag ".expand("<cword>"))<CR>
"

