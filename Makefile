default:
	pdflatex everything.tex

clean:
	rm -fv *.log
	rm -fv sections/*.log
	rm -fv *.aux
	rm -fv sections/*.aux
	rm -fv *.toc
	rm -fv sections/*.toc

cleanpdf: clean
	rm -fv *.pdf


backup: 
	tar czvf ../everything-log.tar.gz ../everything-log/*.tex ../everything-log/*.pdf ../everything-log/sections/* ../everything-log/extraFiles/*

tar:	backup
