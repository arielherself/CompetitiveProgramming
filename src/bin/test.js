// ==UserScript==
// @name         New Userscript
// @namespace    http://tampermonkey.net/
// @version      2024-02-17
// @description  try to take over the world!
// @author       You
// @match        https://codeforces.com/problemset/problem/*
// @match        https://codeforces.com/contest/*/problem/*
// @icon         https://www.google.com/s2/favicons?sz=64&domain=codeforces.com
// @grant        none
// ==/UserScript==

(function() {
    'use strict';
    const url = window.location.pathname.split('/');
    let contest, problem;
    if (url.includes('contest')) {
        contest = url[2];
        problem = url[4];
    } else {
        contest = url[3];
        problem = url[4];
    }
    let button = document.createElement('li');
    let inner = document.createElement('a');
    inner.target = '_blank';
    inner.href = `https://www.luogu.com.cn/problem/solution/CF${contest}${problem}`;
    inner.innerText = 'SOLUTIONS';
    button.appendChild(inner);
    let menu = document.getElementsByClassName('second-level-menu-list')[0];
    menu.insertBefore(button, menu.children[2])
})();