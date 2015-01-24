;; Selection sort
;;
;; Skupoy Sergey. sergey.archlinux@gmail.com, 2015.

(defn ssort [arr]
  (if (empty? arr)
    []
    (_split (rest arr) (first arr) [])))

(defn _split [arr key acc]
  (loop [a arr k key ac acc]
    (if (empty? a)
      (cons k (ssort ac))
      (if (< (first a) k)
        (recur (rest a) (first a) (cons k ac))
        (recur (rest a) k (cons (first a) ac))))))




   



