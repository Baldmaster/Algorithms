;; Insertion sort
;;
;; Skupoy Sergey. sergey.archlinux@gmail.com, 2015.

(defn insort [arr]
  (loop [acc '() l arr] ;;define accumulator list
    (if (empty? l)      ;;if all list elements are processed
      acc               ;;return sorted list
      (recur (insert (first l) acc) (rest l))))) 

(defn insert [k arr]
  (if (empty? arr)      
    (list k)            
    (if (<= k (first arr))
      (cons k arr)          
      (cons (first arr) (insert k (rest arr))))))





