(define TREE '(1 (2 (3 4)) 6 (7 8 9)) )
(define TREE00 '(1 2 3 4 5))

(define mymap
  (lambda (fn ls)
    (if (null? ls)
        '()
        (cons (fn (car ls))
              (map fn (cdr ls)))
        )))

(define map-tree
  (lambda (fn tree)
    (cond ((null? tree) '())
          ((pair? tree) (cons (map-tree fn (car tree)) (map-tree fn (cdr tree))))
          ;木が与えられた場合の処理。
          ;map-treeは元の木と同じ形状の木が答えとなる。
          ;したがって空欄部分の定義は、ドット対のcar部とcdr部の両方に再帰的に適用する。
          ;そして、その結果をconsで繋げる計算となるはずである。
          (else (fn tree))
          )))

(map-tree even? TREE)
;(#f (#t (#f #t)) #t (#f #t #f))
(map-tree (lambda (x) (* x x)) TREE)
;(1 (4 (9 16)) 36 (49 64 81))

(map-tree even? TREE00)
;(#f #t #f #t #f)
(map-tree (lambda (x) (* x x)) TREE00)
;(1 4 9 16 25)