#! /usr/bin/env bash

PROGNAME=$0;
STAND="используется значение по умолчанию";

while [[ -n $@ ]] ; do
case $1 in
        '--help'|'-h')
            echo "
Использование:
    $PROGNAME [ПАРАМЕТР] [ДИРЕКТОРИЯ] [ПРЕФИКС] [МИН] [МАКС]
Удаление файлов с указанным префиксом, длина которых находится в указанном диапазоне.
    -h или --help       Вывести справку (это сообщение) и завершить работу 
    -p                  Вывести процесс работы команды
    --version           Вывести информацию о версии $PROGNAME и завершить работу
Единица измерения min, max - байт"
            exit 0;;
	'--version')
	    echo "
Версия $PROGNAME 1.00"
	    exit 0;;
        '-p')
            INF=y;
            shift;;
        *)
            DIR="$1" 
            shift;
            PR="$1"  
            shift;
            MIN="$1" 
            shift;
            MAX="$1" 
            shift;

            if [ "x${DIR}" = "x" ]
            then
                echo "Не введена директория - $STAND: текущая директория";
                DIR=.;
            fi
            if [ "x${PR}" = "x" ]
            then
                echo "Не введен префикс - $STAND: inf";
                PR=inf;
            fi
            if [ "x${MIN}" = "x" ]
            then
                echo "Не введен минимум - $STAND: 0";
                MIN=0;
            fi
            if [ "x${MAX}" = "x" ]
            then
                echo "Не введен максимум - $STAND: 100000 (~5M)";
                MAX=100000;
            fi

            if [ ! -d "${DIR}" ]
            then
                echo "Такой директории не существует."
                exit 1;
            fi

            NUMBER_REGEXP='^[0-9]+$';
            if ! [[ ${MIN} =~ ${NUMBER_REGEXP} ]]
            then
                echo "Левая граница не является числом - $STAND: 0"
                MIN=0;
            fi
            if ! [[ ${MAX} =~ ${NUMBER_REGEXP} ]]
            then
                echo "Правая граница не является числом - $STAND: 100000 (~5M)"
                MAX=100000;
            fi

            if [ "$MIN" -gt "$MAX" ]
                then echo "Введенная левая граница больше правой "

            fi
            if [ "x${INF}" = "xy" ]
            then
                echo "find ${DIR} -type f -name '${PR}*' -size +${MIN} -size -${MAX}"
            fi
            find "${DIR}" -type f -name "${PR}*" -size +"${MIN}" -size -"${MAX}" -delete
            exit 0;;
    esac;
done;

# Если параметры не введены
echo "Не введены параметры - используются значения по умолчанию:
текущая директория, inf, 0 - 100000 (~5M)"

DIR=.; 
PR=; 
MIN=0; 
MAX=100000; #
echo "find \"${DIR}\" -type f -name \"${PR}*\" -size +\"${MIN}\" -size -\"${MAX}\""
find "${DIR}" -type f -name "${PR}*" -size +"${MIN}" -size -"${MAX}"  -delete




