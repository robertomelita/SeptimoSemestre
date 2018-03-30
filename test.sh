var="$1"
var2="$#"
if [ $var2 = 1 ];
then
$(xrandr --output DP-0 --brightness 0.$var)
echo configurando con brillo ingresado '('0.$var')'
else
$(xrandr --output DP-0 --brightness 0.4)
echo configurando con brillo por defecto
fi
