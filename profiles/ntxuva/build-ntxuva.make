api = 2
core = 7.x

; According to https://github.com/drush-ops/drush/issues/234#issuecomment-27656033
; https://drupal.org/comment/8140319#comment-8140319
; The following change fixed the issue
projects[drupal][type] = core
projects[drupal][version] = 7.34
projects[drupal][download][type] = get
projects[drupal][download][url] = http://ftp.drupal.org/files/projects/drupal-7.34.tar.gz

; Ntxuva Profile
projects[ntxuva][type] = profile
projects[ntxuva][download][type] = "git"
projects[ntxuva][download][url] = "https://github.com/ntxuva/ntxuva-install-profile.git"
projects[ntxuva][download][branch] = "master"
