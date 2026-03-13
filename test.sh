../../run.sh ./src "*" ./out/main.o "-I../strlib/include \
		     	   		      -I ./include \
		  				  -lsqlite3 \
		  			 -L../strlib/out \
		  				  -l:libstr.a"
